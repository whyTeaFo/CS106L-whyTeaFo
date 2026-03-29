#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  std::vector<std::string::iterator> space_itr = find_all(source.begin(),source.end(),isspace);
  std::set<Token> tokens;
  auto token_constructor = [&source](auto it1,auto it2){return Token(source,it1,it2);};
  std::transform(space_itr.begin(),space_itr.end()-1,space_itr.begin()+1,std::inserter(tokens,tokens.end()),token_constructor);
  auto token_empty = [](const Token& token){return token.content.empty();};
  std::erase_if(tokens,token_empty);
  return Corpus(tokens);
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;
  auto tokenToMisspelling = [&dictionary](const auto& token){
    auto view = dictionary | rv::filter([&token](const auto& str){return levenshtein(str,token.content) == 1;});
    std::set<std::string> suggestions(view.begin(),view.end());
    return Misspelling(token,suggestions);
  };
  auto view = source | rv::filter([&dictionary](const auto& token){return !dictionary.contains(token.content);})
                     | rv::transform(tokenToMisspelling)
                     | rv::filter([](const auto& misspelling){return !misspelling.suggestions.empty();});
  return std::set<Misspelling>(view.begin(),view.end());
};

/* Helper methods */

#include "utils.cpp"
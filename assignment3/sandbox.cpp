/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include <iostream>
#include "class.h"
using std::cout;

void sandbox() {
  AIAgent<std::string> Deepseek("deepseek","R1");
  AIAgent<int> ChatGPT("ChatGPT",4);
  std::string username = "whyTeaFo";

  Deepseek.printResponse(username);
  ChatGPT.printResponse(username);

  std::string dsName = Deepseek.getName();
  cout << dsName << '\n';
  ChatGPT.updateVersion(5);

  Deepseek.printResponse(username);
  ChatGPT.printResponse(username);
}
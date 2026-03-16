#include <string>
#include <iostream>
using std::cout;
using std::string;

template <typename T>
class AIAgent{
private:
    string name;
    T version;
    std::string& nameSwitch(){
        return name.append(" AI");
    }
public:
    AIAgent(const std::string& name,const T& version){
        this->name = name;
        nameSwitch();
        this->version = version;
    }
    AIAgent() = default;
    ~AIAgent() = default;

    const std::string& getName() const {
        return name;
    }

    std::string& getName(){
        return name;
    }

    const T& getVersion() const {
        return version;
    }

    T& getVersion(){
        return version;
    }

    void updateVersion(const T& version){
        this->version = version;
    }
    void printResponse(const std::string& username) const {
        cout << "Hello " << username << ",this is "
        << name << " (version:" << version << ')' << '\n';
    }
};
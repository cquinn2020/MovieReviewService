#ifndef USER_H
#define USER_H
#include <string>

class User
{
private:
    std::string name;

public:
    User(std::string name);
    User();
    ~User();

    std::string getName();
    void setName(std::string);
};

#endif
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
protected:
    int userId;
    string name;
    string email;

public:

    User();

    User(int id, string n, string e);

    void setUserId(int id);
    void setName(string n);
    void setEmail(string e);
     
    int getUserId() const;
    string getName() const;
    string getEmail() const;

    bool isValidEmail(string email) const;
bool isValidName(string name) const;
bool isGmail(string email) const;

    void displayInfo() const;
};

#endif
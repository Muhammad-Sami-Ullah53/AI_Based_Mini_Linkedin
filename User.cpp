#include "User.h"

User::User()
{
    userId = 0;
    name = "";
    email = "";
}

User::User(int id,
           string n,
           string e)
{
    userId = 0;
    name = "";
    email = "";

    setUserId(id);
    setName(n);
    setEmail(e);
}

void User::setUserId(int id)
{
    if(id > 0)
    {
        userId = id;
    }
}

bool User::isValidName(string name) const
{
    if(name.empty())
    {
        return false;
    }

    for(int i = 0; i < name.length(); i++)
    {
        if(
            !isalpha(name[i])
            &&
            name[i] != ' '
        )
        {
            return false;
        }
    }

    return true;
}

void User::setName(string n)
{
    if(isValidName(n))
    {
        name = n;
    }
}



bool User::isValidEmail(string email) const
{
    bool hasAt = false;
    bool hasDot = false;

    for(int i = 0; i < email.length(); i++)
    {
        if(email[i] == '@')
        {
            hasAt = true;
        }

        if(email[i] == '.')
        {
            hasDot = true;
        }
    }

    return hasAt && hasDot;
}

void User::setEmail(string e)
{
    if(!e.empty() && isGmail(e))
    {
        email = e;
    }
}

bool User::isGmail(string email) const
{
    if(email.length() < 10)
    {
        return false;
    }

    string last10 = email.substr(
        email.length() - 10
    );

    if(last10 == "@gmail.com")
    {
        return true;
    }

    return false;
}

int User::getUserId() const
{
    return userId;
}

string User::getName() const
{
    return name;
}

string User::getEmail() const
{
    return email;
}

void User::displayInfo() const
{
    cout << "ID: " << userId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
}
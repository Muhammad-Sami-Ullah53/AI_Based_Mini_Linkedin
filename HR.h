#ifndef HR_H
#define HR_H

#include "User.h"
#include <string>

using namespace std;

class HR : public User
{
private:
    string companyName;
    string designation;

public:
    HR();

    HR(int id,
       string n,
       string e,
       string company,
       string desig);

    void setCompanyName(string company);
    void setDesignation(string desig);

    string getCompanyName() const;
    string getDesignation() const;

    void displayHRProfile() const;
};

#endif
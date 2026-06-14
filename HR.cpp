#include "HR.h"

HR::HR() : User()
{
    companyName = "";
    designation = "";
}

HR::HR(int id,
       string n,
       string e,
       string company,
       string desig)
       : User(id, n, e)
{
    companyName = company;
    designation = desig;
}

void HR::setCompanyName(string company)
{
    if(!company.empty())
    {
        companyName = company;
    }
}

void HR::setDesignation(string desig)
{
    if(!desig.empty())
    {
        designation = desig;
    }
}

string HR::getCompanyName() const
{
    return companyName;
}

string HR::getDesignation() const
{
    return designation;
}

void HR::displayHRProfile() const
{
    cout << "HR Profile" << endl;
    cout << "----------" << endl;

    cout << "ID: " << userId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Company: " << companyName << endl;
    cout << "Designation: " << designation << endl;
}
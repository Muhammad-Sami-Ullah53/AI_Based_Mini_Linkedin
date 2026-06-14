#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class user
{
private:
    string name;
    string password;

public:
    void registerUser()
    {
        ofstream file("user.txt", ios::app);
        cout << "Enter name:";
        getline(cin, name);
        cout << "Enter password:";
        getline(cin, password);
        file << name << " " << password << " " << endl;
        file.close();
        cout << "REGISTRATION SUCCESSFUL" << endl;
    }
    bool loginUser()
    {
        string u, p;
        string loginName, loginPassword;
        cout << "Enter name:";
        cin >> u;
        cout << "Enter password:";
        cin >> p;
        ifstream file("user.txt");
        if (!file)
        {
            cout << "File not found\n";
            return false;
        }
        while (file >> loginName >> loginPassword)
        {
            if (u == loginName && p == loginPassword)
            {

                return true;
            }
        }
        file.close();
        return false;
    }
};

class interview
{
private:
    string field;
    string level;

public:
    void selectField()
    {
        int choice;
        cout << "\n====Select Field====\n";
        cout << "1.Web Development\n";
        cout << "2.Mobile App Development\n";
        cout << "3.Data Science\n";
        cout << "4.Machine Learning\n";
        cout << "5.Artificial Intelligence\n";
        cout << "6.C++\n";
        cout << "7.Python\n";
        cout << "8.Database(SQL)\n";
        cout << "9.Cyber Security\n";
        cout << "10.software Engineering\n";
        cout << "Enter choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            field = "Web Development";
            break;
        case 2:
            field = "Mobile App Development";
            break;
        case 3:
            field = "Data Science";
            break;
        case 4:
            field = "Machine Learning";
            break;
        case 5:
            field = "Artificial Intelligence";
            break;
        case 6:
            field = "C++";
            break;
        case 7:
            field = "Python";
            break;
        case 8:
            field = "Database(SQL)";
            break;
        case 9:
            field = "Cyber Security";
            break;
        case 10:
            field = "software Engineering";
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    void selectLevel()
    {
        int choice;
        cout << "\n====Select level====\n";
        cout << "1.Easy\n2.Medium\n3.Hard" << endl;
        cin >> choice;
        if (choice == 1)
            level = "Easy";
        else if (choice == 2)
            level = "Medium";
        else if (choice == 3)
            level = "Hard";
        else
            cout << "Invalid choice" << endl;
    }
    void display()
    {
        cout << "Selestes Field:" << field << endl;
        cout << "Selected level:" << level << endl;
    }
};
int main()
{
    user u;
    int choice;
    do
    {
        cout << "1.Registration\n2.Login\n3.Exit" << endl;
        cout << "Enter choice" << endl;
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            u.registerUser();
        }
        else if (choice == 2)
        {
            if (u.loginUser())
            {
                cout << "Login successful" << endl;
                interview i;
                i.selectField();
                i.selectLevel();
                i.display();
            }
        }
        else if (choice == 3)
        {
            cout << "Exit....." << endl;
        }
        else
        {
            cout << "Invalid login" << endl;
        }
    } while (choice != 3);
    return 0;
}
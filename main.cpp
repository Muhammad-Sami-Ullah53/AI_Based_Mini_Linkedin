// #include "Portal.h"

// int main()
// {
//     JobPortalSystem system;

//     system.mainMenu();

//     return 0;
// }



#include "Portal.h"

int main()
{
    

    JobPortalSystem system;

    system.loadAllData();

    system.mainMenu();

    system.saveAllData();

    return 0;
}


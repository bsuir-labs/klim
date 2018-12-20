//#include "InsuranceKeeper.h"
#include "DataManager.h"
#include "UIController.h"
#include "Authorization.h"
#include "LoginView.h"

const char DATA_SOURCE[] = "data.bin";
const char USERS_SOURCE[] = "users.bin";

int setup_data_manager(DataManager&);
int setup_authorization(Authorization&);

int main()
{
    DataManager data_manager;
    setup_data_manager(data_manager);

    UIController controller(&data_manager);
    
    Authorization auth;
    setup_authorization(auth);

    controller.setLayout(new LoginView(&auth));

    while (true)
    {
        controller.clr_scr();
        controller.render();
        controller.interact();
    }

    return 0;
}

int setup_data_manager(DataManager& dm)
{
    dm.setSource(DATA_SOURCE);
    try {
        dm.loadData();
    }
    catch (...)
    {
        dm.saveData();
        return 1;
    }
    return 0;
}

int setup_authorization(Authorization& auth)
{
    auth.setSource(USERS_SOURCE);
    try {
        auth.loadData();
    }
    catch (...) {
        auth.addUser(
            "superadmin",
            "superpassword"
        );
        auth.saveData();
        return 1;
    }
    return 0;
}
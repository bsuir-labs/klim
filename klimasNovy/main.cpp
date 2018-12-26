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
    DataManager data_manager;  // Структура для работы с данными
    setup_data_manager(data_manager); // Инициализация структуры
    
    Authorization auth; // Структура для авторизации
    setup_authorization(auth); // инициализация

    UIController controller(&data_manager, &auth); 

    controller.setLayout(new LoginView());

    while (true)
    {
        controller.clr_scr();
        controller.render();
    }

    return 0;
}

int setup_data_manager(DataManager& dm)
{
    dm.setSource(DATA_SOURCE); // Задаём имя файла с данными
    try {
        dm.loadData(); // пытаемся открыть файл
    }
    catch (...) // если что-то не получилось
    {
        dm.saveData(); // создаём новый
        return 1;
    }
    return 0;
}

int setup_authorization(Authorization& auth)
{
    auth.setSource(USERS_SOURCE); // Задаём имя файла с пользователями
    try {
        auth.loadData();
    }
    catch (...) {
        auth.addUser( // стандартный пользователь
            "superadmin",
            "superpassword"
        );
        auth.saveData();
        return 1;
    }
    return 0;
}
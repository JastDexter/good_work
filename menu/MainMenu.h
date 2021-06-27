#ifndef GOOD_WORK_MAINMENU_H
#define GOOD_WORK_MAINMENU_H


#include "Menu.h"
#include "IntTestMenu.h"
#include "DoubleTestMenu.h"
#include "LogTestMenu.h"
#include <string>

class MainMenu : public Menu {
private:
    IntTestMenu *intTestMenu;
    DoubleTestMenu *doubleTestMenu;
    LogTestMenu *logTestMenu;
    const std::string items[4] = {"1. Test list with integer",
                                  "2. Test list with double",
                                  "3. Test class attendance log",
                                  "4. Quit"};
    const int length = 4;
    const std::string repeat = "Please, input valid value";

public:
    MainMenu();

    void show() override;

    Menu *result(std::string input) override;
};


#endif

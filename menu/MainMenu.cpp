#include "MainMenu.h"

Menu *MainMenu::result(std::string input) {
    try {
        int choice = std::stoi(input);

        switch (choice) {
            case 1:
                return intTestMenu;
            case 2:
                return doubleTestMenu;
            case 3:
                return logTestMenu;
            case 4:
                return nullptr;
            default: {
                std::cout << std::endl << this->repeat;
            }
        }

    } catch (...) {
        std::cout << std::endl << this->repeat;
    }
    return this;
}

void MainMenu::show() {
    for (const auto &item: items)
        std::cout << std::endl << item;
}


MainMenu::MainMenu() {
    intTestMenu = new IntTestMenu(this);
    doubleTestMenu = new DoubleTestMenu(this);
    logTestMenu = new LogTestMenu(this);
}

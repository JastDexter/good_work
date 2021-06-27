#ifndef GOOD_WORK_MENU_H
#define GOOD_WORK_MENU_H

#include <iostream>
#include <string>

class Menu {
protected:
    Menu *parent{nullptr};
public:
    Menu(Menu *parent) : parent(parent) {}

    Menu() = default;

    virtual void show() = 0;

    virtual Menu *result(std::string input) = 0;
};


#endif

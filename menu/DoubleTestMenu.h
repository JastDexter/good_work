#ifndef GOOD_WORK_DOUBLETESTMENU_H
#define GOOD_WORK_DOUBLETESTMENU_H


#include "Menu.h"
#include "../list/LinkedList.h"

class DoubleTestMenu : public Menu {
    const std::string items[13] = {"1. Push back new int",
                                   "2. Delete from position",
                                   "3. Insert new int in position",
                                   "4. Get from position",
                                   "5. Sort",
                                   "6. Insert new int by order (include sort)",
                                   "7. Save to binary file",
                                   "8. Load from binary",
                                   "9. Find equals number",
                                   "10. Find items larger number",
                                   "11. Find items less number",
                                   "12. Back",
                                   "13. Quit"};
    const std::string repeat = "Please, input valid value";
    const int length = 13;
    LinkedList<double> *list{new LinkedList<double>()};
public:
    void show() override;

    Menu *result(std::string input) override;

    explicit DoubleTestMenu(Menu *parent) : Menu(parent) {};
};


#endif

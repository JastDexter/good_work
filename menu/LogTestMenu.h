#ifndef GOOD_WORK_LOGTESTMENU_H
#define GOOD_WORK_LOGTESTMENU_H


#include "Menu.h"
#include "../class_attendance_log/ClassAttendanceLogFacade.h"

class LogTestMenu : public Menu {
    const std::string items[15] = {"1. Add listener",
                                   "2. Remove listener from position",
                                   "3. Add group to listener at position",
                                   "4. Get listener from position",
                                   "5. Add date to listener",
                                   "6. Add date to group",
                                   "7. Find listeners attending by date",
                                   "8. Find listeners by group name",
                                   "9. Find listeners by family ",
                                   "10. Sort",
                                   "11. Save to binary file",
                                   "12. Load from binary",
                                   "13. Show full class attendance log",
                                   "14. Back",
                                   "15. Quit"};
    const std::string repeat = "Please, input valid value";
    ClassAttendanceLogFacade *log{new ClassAttendanceLogFacade()};
public:
    void show() override;

    Menu *result(std::string input) override;

    explicit LogTestMenu(Menu *parent) : Menu(parent) {};
};


#endif

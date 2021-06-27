#include <iostream>
#include <list>
#include "list/LinkedList.h"
#include "stdlib.h"
#include "class_attendance_log/ClassAttendanceLogFacade.h"
#include "menu/Menu.h"
#include "menu/MainMenu.h"


int main() {
/*
    */
/*const char* FName = "C:\\1.txt";
    auto *list = new CustomList<int>();
    auto *list3 = new CustomList<CustomList<void>>();
    for (int i = 10; i > 0; i--)
        list->insert(i);
    std::ofstream out(FName, std::ios::binary);
    out.close();
    //list->sort();
    std::ifstream in(FName, std::ios::binary);
    list3->load_binary(in);
    list->load_binary(in);*//*


*/
/*    auto list = LinkedList<Integer &>();
    Integer *nodes[10];
    for (int i = 9; i >= 0; i--)
        nodes[i] = new Integer(9 - i);
    for (auto &node : nodes)
        list.insert_sorted(*node);*//*


*/
/*    auto list = LinkedList<int>();
    for (int i = 9; i >= 0; i--)
        list.insert_sorted(i);

    const char *FName = "C:\\1.txt";

    std::ofstream out(FName, std::ios::binary);
    list.save_binary(out);
    out.close();

    auto list_2 = new LinkedList<int>();
    std::ifstream in(FName, std::ios::binary);

    list_2->load_binary(in);
    in.close();*//*



*/
/*    auto list = new LinkedList<int>();
    for (int i = 10; i > 0; i--)
        list->insert(i);

    auto some = list->get(2);*//*

    auto log = new ClassAttendanceLogFacade();
    log->addListener("Fine");
    log->removeListener(0);
    log->addListener("Zubenko M.P.", "6409");
    log->addListener("Lebed M.P.");
    log->addListener("Fine2", "6409");
    log->addDate(0, *(new Date(2012, 12, 31)));
    log->addDate(0, *(new Date()));
    log->addDate(1, *(new Date()));
    log->addDate("6409", *(new Date(2014, 12, 31)));
    log->writeFullLog();
    std::cout << "-----------------------------------" << std::endl;
    //log->displayByDate(*(new Date()));

    const char *FName = "C:\\1.txt";

    std::ofstream out(FName, std::ios::binary);
    log->save_binary(out);
    out.close();

    auto log_2 = new ClassAttendanceLogFacade();
    std::ifstream in(FName, std::ios::binary);
    log_2->load_binary(in);
    in.close();
    log_2->writeFullLog();
    std::cout << "-----------------------------------" << std::endl;
    log_2->displayByDate(*(new Date()));
    std::cout << "-----------------------------------" << std::endl;
*/
/*    log_2->sort([](Listener *left, Listener *right) -> int {
        if (left > right)
            return -1;
        else if (left == right)
            return 0;
        else
            return 1;
    });*//*

log_2->sort();
    log->writeFullLog();
    std::cout << "-----------------------------------" << std::endl;
    log_2->writeFullLog();
*/

    Menu *menu = new MainMenu();
    while (menu) {
        menu->show();
        std::string input;
        std::cout << std::endl << "You choice: ";
        std::cin >> input;
        menu = menu->result(input);
        system("pause");
        system("CLS");
    }
    return 0;
}

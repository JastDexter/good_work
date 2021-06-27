#include "LogTestMenu.h"


Menu *LogTestMenu::result(std::string input) {
    try {
        int choice = std::stoi(input);

        switch (choice) {
            case 1: {
                std::cout << std::endl << "Input family: ";
                std::cin >> input;
                std::string family = input;
                std::cout << std::endl << "Input group: ";
                std::cin >> input;
                std::string group = input;
                if(group.empty())
                    log->addListener(family);
                else
                    log->addListener(family, group);
                return this;
            }
            case 2: {
                std::cout << std::endl << "Input removed position: ";
                std::cin >> input;
                int removed = std::stoi(input);
                log->removeListener(removed);
                return this;
            }
            case 3: {
                std::cout << std::endl << "Input position: ";
                std::cin >> input;
                int position = std::stoi(input);
                std::cout << std::endl << "Input group name: ";
                std::cin >> input;
                log->addGroup(position, input);
                return this;
            }
            case 4: {
                std::cout << std::endl << "Input position: ";
                std::cin >> input;
                int position = std::stoi(input);
                log->displayListener(position);
                return this;
            }
            case 5: {
                std::cout << std::endl << "Input year: ";
                std::cin >> input;
                int year = std::stoi(input);
                std::cout << std::endl << "Input month(number): ";
                std::cin >> input;
                int month = std::stoi(input);
                std::cout << std::endl << "Input day: ";
                std::cin >> input;
                int day = std::stoi(input);
                std::cout << std::endl << "Input position: ";
                std::cin >> input;
                int position = std::stoi(input);
                log->addDate(position, *(new Date(year, month, day)));
                return this;
            }
            case 6: {
                std::cout << std::endl << "Input year: ";
                std::cin >> input;
                int year = std::stoi(input);
                std::cout << std::endl << "Input month(number): ";
                std::cin >> input;
                int month = std::stoi(input);
                std::cout << std::endl << "Input day: ";
                std::cin >> input;
                int day = std::stoi(input);
                std::cout << std::endl << "Input group name: ";
                std::cin >> input;
                log->addDate(input, *(new Date(year, month, day)));
                return this;
            }
            case 7: {
                std::cout << std::endl << "Input year: ";
                std::cin >> input;
                int year = std::stoi(input);
                std::cout << std::endl << "Input month(number): ";
                std::cin >> input;
                int month = std::stoi(input);
                std::cout << std::endl << "Input day: ";
                std::cin >> input;
                int day = std::stoi(input);
                log->displayByDate( *(new Date(year, month, day)));
                return this;
            }
            case 8: {
                std::cout << std::endl << "Input group name: ";
                std::cin >> input;
                log->displayByGroup(input);
                return this;
            }
            case 9: {
                std::cout << std::endl << "Input family name: ";
                std::cin >> input;
                log->displayByFamily(input);
                return this;
            }
            case 10: {
                log->sort();
                return this;
            }
            case 11: {
                std::cout << std::endl << "Input file name: ";
                std::cin >> input;
                std::ofstream out(input, std::ios::binary);
                log->save_binary(out);
                out.close();
                return this;
            }
            case 12:{
                std::cout << std::endl << "Input file name: ";
                std::cin >> input;
                std::ifstream in(input, std::ios::binary);
                log->load_binary(in);
                in.close();
                return this;
            }
            case 13:{
                log->writeFullLog();
                return this;
            }
            case 14:
                return this->parent;
            case 15:
                return nullptr;
            default: {
                std::cout << std::endl << repeat;
            }
        }

    } catch (...) {
        std::cout << std::endl << repeat;
    }
    return this;
}

void LogTestMenu::show() {
    //std::cout << std::endl << "Log listeners count: " << log;
    //std::cout << std::endl << "List items: ";
    /*for (auto item: *list)
        std::cout << item << " ";*/
    for (const auto &item: items)
        std::cout << std::endl << item;
}

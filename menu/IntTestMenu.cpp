#include "IntTestMenu.h"


Menu *IntTestMenu::result(std::string input) {
    try {
        int choice = std::stoi(input);

        switch (choice) {
            case 1: {
                std::cout << std::endl << "Input added value: ";
                std::cin >> input;
                int added = std::stoi(input);
                list->insert(added);
                return this;
            }
            case 2: {
                std::cout << std::endl << "Input removed position: ";
                std::cin >> input;
                int removed = std::stoi(input);
                list->remove(removed);
                return this;
            }
            case 3: {
                std::cout << std::endl << "Input added value: ";
                std::cin >> input;
                int added = std::stoi(input);
                std::cout << std::endl << "Input position: ";
                std::cin >> input;
                int position = std::stoi(input);
                list->insert(added, position);
                return this;
            }
            case 4: {
                std::cout << std::endl << "Input position: ";
                std::cin >> input;
                int position = std::stoi(input);
                std::cout << std::endl << "Value at position " << position << " is " << list->get(position);
                return this;
            }
            case 5: {
                list->sort();
                return this;
            }
            case 6: {
                std::cout << std::endl << "Input added value: ";
                std::cin >> input;
                int added = std::stoi(input);
                list->insert_sorted(added);
                return this;
            }
            case 7: {
                std::cout << std::endl << "Input file name: ";
                std::cin >> input;
                std::ofstream out(input, std::ios::binary);
                list->save_binary(out);
                out.close();
                return this;
            }
            case 8: {
                std::cout << std::endl << "Input file name: ";
                std::cin >> input;
                std::ifstream in(input, std::ios::binary);
                list->load_binary(in);
                in.close();
                return this;
            }
            case 9: {
                std::cout << std::endl << "Input number: ";
                std::cin >> input;
                int about = std::stoi(input);
                auto temp = list->find([](int data, int about) -> bool {
                    return data == about;
                }, about);
                std::cout << std::endl << "Items: ";
                for (auto item: temp)
                    std::cout << item << " ";
                return this;
            }
            case 10: {
                std::cout << std::endl << "Input number: ";
                std::cin >> input;
                int about = std::stoi(input);
                auto temp = list->find([](int data, int about) -> bool {
                    return data > about;
                }, about);
                std::cout << std::endl << "Items: ";
                for (auto item: temp)
                    std::cout << item << " ";
                return this;
            }
            case 11: {
                std::cout << std::endl << "Input number: ";
                std::cin >> input;
                int about = std::stoi(input);
                auto temp = list->find([](int data, int about) -> bool {
                    return data < about;
                }, about);
                std::cout << std::endl << "Items: ";
                for (auto item: temp)
                    std::cout << item << " ";
                return this;
            }
            case 12:
                return this->parent;
            case 13:
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

void IntTestMenu::show() {
    std::cout << std::endl << "List length: " << list->size();
    std::cout << std::endl << "List items: ";
    for (auto item: *list)
        std::cout << item << " ";
    for (const auto &item: items)
        std::cout << std::endl << item;
}

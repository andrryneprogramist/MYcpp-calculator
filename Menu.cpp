#include <iostream>
#include <limits>
#include <iomanip>
#include "StandardMenu.h"
#include "CalendarMenu.h"
#include "Menu.h"
#include <vector>
#include <string>

    void Menu::clear() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void Menu::printResult(const std::string& operation, double result) {
        std::cout << "Результат: " << operation << " = " << result << std::endl;
        //history.push_back(operation + " = " + std::to_string(result));
    }
    void Menu::showMenu() {
        std::cout << "\n=== КОНСОЛЬНЫЙ КАЛЬКУЛЯТОР ===" << std::endl;
        std::cout << "1. Стандартный режим" << std::endl;
        std::cout << "2. Инженерный" << std::endl;
        std::cout << "3. Программист" << std::endl;
        std::cout << "4. Работа с Датами" << std::endl;
        std::cout << "5. Преобразователь величин" << std::endl;
        std::cout << "6. Работа со строками" << std::endl;
        std::cout << "7. Показать историю операций" << std::endl;
        std::cout << "8. Очистить историю" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите операцию: ";
    }
    void Menu::run() {
        int choice;

        do {
            Menu Menu();
            std::cin >> choice;
            clear();

            switch (choice) {
            case 1: {
                std::cout << std::endl;
                std::cout << "\n=== Стандартный режим ===" << std::endl;
                StandartMenu().showSMenu();
                StandartMenu().SMrun();
                break;
            }
            case 2: {
                std::cout << "\n=== Инженерный режим ===" << std::endl;
                //run->EngineerMenu.cpp
                break;
            }
            case 3: {
                std::cout << "\n=== Программист ===" << std::endl;
                break;
            }
            case 4: {
                std::cout << "\n=== Работа с датами ===" << std::endl;
                std::cout << "\033[2J\033[H";// очистка консоли через эскейп последовательность
                CalendarMenu CalendarMenu;
                CalendarMenu.showCMenu();
                CalendarMenu.runCM();

                break;
            }
            case 5: {
                std::cout << "\n=== Преобразователь величин ===" << std::endl;

                break;
            }
            case 6: {
                std::cout << "\n=== Работа со строками ===" << std::endl;

                break;
            }
            case 7: {
                
                break;
            }
            case 8: {
                
                break;
            }
            case 0: { // Выход
                std::cout << "\nДо свидания!" << std::endl;
                break;
            }
            default: {
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
            }
            }

            if (choice != 0) {
                std::cout << "\nНажмите Enter для продолжения...";
                std::cin.get();
            }

        } while (choice != 0);
    }













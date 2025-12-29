#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <string>
#include "StandardMenu.h"
#include "Menu.h"




    void StandartMenu::SMclear() {
        std::cout << "\033[2J\033[H";

    }

    void StandartMenu::showSMenu() {
        std::cout << "1. Сложение" << std::endl;
        std::cout << "2. Вычитание" << std::endl;
        std::cout << "3. Умножение" << std::endl;
        std::cout << "4. Деление" << std::endl;
        std::cout << "5. Квадрат числа" << std::endl;
        std::cout << "6. Корень квадратный из числа" << std::endl;
        std::cout << "7. Обратное число" << std::endl;
        std::cout << "8. Процент от числа" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите операцию: ";
    }

    void StandartMenu::SMrun() {
        int choice;

        do {
            StandartMenu();
            std::cin >> choice;
            switch (choice) {
            case 1: {
                
                std::cout << "\n=== Сложение ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа ";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << '+' << b << '=' << add(a, b)<<std::endl << "Выберите операцию еще раз или выйдите: ";

                break;
            }
            case 2: {
                std::cout << "\n=== Вычитание ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа ";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << '-' << b << '=' << substract(a, b)<<std::endl << "Выберите операцию еще раз или выйдите: ";
                break;
            }
            case 3: {
                std::cout << "\n=== Умножение ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа ";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << '*' << b << '=' << multiply(a, b)<<std::endl << "Выберите операцию еще раз или выйдите: ";
                break;
            }
            case 4: {
                std::cout << "\n=== Деление ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа ";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << '/' << b << '=' << divide(a, b)<< std::endl << "Выберите операцию еще раз или выйдите: ";
                break;
            }
            case 5: {
                std::cout << "\n=== Квадрат числа ===" << std::endl;
                double a;
                std::cout << "Введите число ";
                std::cin >> a;
                std::cout << a<<"^2" << '=' << MyPower2(a)<<std::endl << "Выберите операцию еще раз или выйдите: ";
                break;
            }
            case 6: {
                std::cout << "\n=== Корень квадратный из числа === " << std::endl;
                double a;
                std::cout << "Введите число ";
                std::cin >> a;
                std::cout << a << "^(1/2)" << ' = ' << squareroot(a)<<std::endl << "Выберите операцию еще раз или выйдите: ";
                break;
            }
            case 7: {
                std::cout << "\n=== Обратное число ===" << std::endl;
                double a;
                std::cout << "Введите число ";
                std::cin >> a;
                std::cout << "1/" << a << '=' << reciprocal(a)<<std::endl << "Выберите операцию еще раз или выйдите: ";
                break;
            }
            case 8: {
                std::cout << "\n=== Процент от числа ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа ";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << "процентов от " << b << '=' << percent(a, b) << std::endl<<"Выберите операцию еще раз или выйдите: ";
                break;
            }
            case 0: { // Выход
                SMclear();
                Menu menu;
                menu.showMenu();
                menu.run();
                break;
            }
            default: {
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
            }
            }
        } while (choice != 0);
    }













//void printResult(const std::string& operation, double result) {
//    std::cout << "Результат: " << operation << " = " << result << std::endl;
//   // history.push_back(operation + " = " + std::to_string(result));
//}




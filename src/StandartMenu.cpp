#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <conio.h>
#include <string>
#include "Standard.h"
#include "Menu.h"


class StandartMenu {
private:
   // std::vector<std::string> history;

    void SMclear() {
        std::cout << "\033[2J\033[H";

    }

public:
    void showSMenu() {
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

    void SMrun() {
        int choice;

        do {
            StandartMenu();
            std::cin >> choice;
            SMclear();

            switch (choice) {
            case 1: {
                
                std::cout << "\n=== Сложение ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << '+' << b << '=' << add(a, b);

                break;
            }
            case 2: {
                std::cout << "\n=== Вычитание ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << '-' << b << '=' << substract(a, b);
                break;
            }
            case 3: {
                std::cout << "\n=== Умножение ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << '*' << b << '=' << multiply(a, b);
                break;
            }
            case 4: {
                std::cout << "\n=== Деление ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << '/' << b << '=' << divide(a, b);
                break;
            }
            case 5: {
                std::cout << "\n=== Квадрат числа ===" << std::endl;
                double a;
                std::cout << "Введите число";
                std::cin >> a;
                std::cout << a<<"^2" << '=' << MyPower2(a);
                break;
            }
            case 6: {
                std::cout << "\n=== Корень квадратный из числа ===" << std::endl;
                double a;
                std::cout << "Введите число";
                std::cin >> a;
                std::cout << a << "^(1/2)" << '=' << squareroot(a);
                break;
            }
            case 7: {
                std::cout << "\n=== Обратное число ===" << std::endl;
                double a;
                std::cout << "Введите число";
                std::cin >> a;
                std::cout << "1/" << a << '=' << reciprocal(a);
                break;
            }
            case 8: {
                std::cout << "\n=== Процент от числа ===" << std::endl;
                double a, b;
                std::cout << "Введите 2 числа";
                std::cin >> a;
                std::cin >> b;
                std::cout << a << "процентов от " << b << '=' << percent(a, b);
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

            if (choice != 0) {
                std::cout << "\nНеверный выбор";
                std::cin.get();
            }

        } while (choice != 0);
    }
};












//void printResult(const std::string& operation, double result) {
//    std::cout << "Результат: " << operation << " = " << result << std::endl;
//   // history.push_back(operation + " = " + std::to_string(result));
//}




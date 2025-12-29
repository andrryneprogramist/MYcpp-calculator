#include <iostream>
#include <sstream>
#include <cmath>
#include <stack>
#include "ExtendedCalc.h"
#include "Menu.h"

using namespace std;

const double Pi = acos(-1); //Объявляем значение числа Пи

double Sin(double x) { //Функция для округления значение синуса
    return (round(sin(x) * 10000000) / 10000000);
}                                                                              ///////////////////СВОЮ РЕАЛИЗАЦИЮ ДОБАВИТЬ

double Cos(double x) { //Функция для округления значение косинуса
    return (round(cos(x) * 10000000) / 10000000);
}

double Ctg(double x) { //Функция для расчета котангенса
    double a = cos(x);
    double b = Sin(x);
    return (a / b);
}



struct Leksema 
{
    char type; // 0 это число , "+" сложение, "-" вычитание и тд.
    double value; //Значение (только для чисел). У операций значение всегда "0"
};

bool Maths(stack <Leksema>& Stack_n, stack <Leksema>& Stack_o, Leksema& item) { //Математическая функция, которая производит расчеты
    //Функция имеет тип bool, чтобы при возникновении какой-либо ошибки возвращать "false"
    double a, b, c;
    a = Stack_n.top().value; //Берется верхнее число из стека с числами
    Stack_n.pop(); //Удаляется верхнее число из стека с числами
    switch (Stack_o.top().type) {  //Проверяется тип верхней операции из стека с операциями
    case '+': //Если тип верхней операции из стека с операциями сложение
        b = Stack_n.top().value;
        Stack_n.pop();
        c = a + b;
        item.type = '0';
        item.value = c;
        Stack_n.push(item); //Результат операции кладется обратно в стек с числами
        Stack_o.pop();
        break;

    case '-':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = b - a;
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '^':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = pow(b, a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '*':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = a * b;
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '/':
        b = Stack_n.top().value;
        if (a == 0) {
            cerr << "\nНа 0 делить нельзя!\n";
            return false;
        }
        else {
            Stack_n.pop();
            c = (b / a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 's':
        c = Sin(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case 'c':
        c = Cos(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case 't':
        if (Cos(a) == 0) {
            cerr << "\nНеверный аргумент для тангенса!\n";
            return false;
        }
        else {
            c = tan(a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 'g':
        if (Sin(a) == 0) {
            cerr << "\nНеверный аргумент для котангенса!\n";
            return false;
        }
        else {
            c = Ctg(a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 'e':
        c = exp(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    default:
        cerr << "\nОшибка!\n";
        return false;
        break;
    }
    return true;
}

int getRang(char Ch) { //Функция возвращает приоритет операции: "1" для сложения и вычитания, "2" для умножения и деления и т.д.
    if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'g' || Ch == 'e')return 4;
    if (Ch == '^')return 3;
    if (Ch == '+' || Ch == '-')return 1;
    if (Ch == '*' || Ch == '/')return 2;
    else return 0;
}

void Extended::ExtMain()
    {
        while (true) {
            system("cls");
            cout<<"==== Строковый калькулятор ====\n";
            cout << "Инструкция: введите выражение, где Pi=p, число e = e(1), есть sin, cos, tan, ctg,    g - выход, при неправильном вводе Ввод начнеся заного! \n";
            std::string str;
            getline(cin, str);
            stringstream sstr{ str };

            char Ch;
            double value;
            bool flag = true;
            stack<Leksema> Stack_n; //Стек с числами
            stack<Leksema> Stack_o; //Стек с операциями
            Leksema item; 

            
               /* std::cout << "\033[2J\033[H";
                Menu menu;
                menu.showMenu();
                menu.run();
                break;
            */
            while (true) {
                Ch = sstr.peek(); //Смотрим на первый символ
                if (Ch == 'g') {
                    std::cout << "\033[2J\033[H";
                    Menu menu;
                    menu.showMenu();
                    menu.run();
                    break;
                }
                if (Ch == ' ') {
                    sstr.ignore();
                    continue;
                }
                if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'e') { //Если прочитана функция
                    char foo[3];
                    for (int i = 0; i < 3; i++) {
                        Ch = sstr.peek();
                        foo[i] = Ch;
                        sstr.ignore();
                    }
                    if (foo[0] == 's' && foo[1] == 'i' && foo[2] == 'n') { //Если прочитанная функция - синус
                        item.type = 's';
                        item.value = 0;
                        Stack_o.push(item);
                        continue;
                    }
                    if (foo[0] == 'c' && foo[1] == 'o' && foo[2] == 's') { //Если прочитанная функция - косинус
                        item.type = 'c';
                        item.value = 0;
                        Stack_o.push(item);
                        continue;
                    }
                    if (foo[0] == 't' && foo[1] == 'a' && foo[2] == 'n') { //Если прочитанная функция - тангенс
                        item.type = 't';
                        item.value = 0;
                        Stack_o.push(item);
                        continue;
                    }
                    if (foo[0] == 'c' && foo[1] == 't' && foo[2] == 'g') { //Если прочитанная функция - котангенс
                        item.type = 'g';
                        item.value = 0;
                        Stack_o.push(item); 
                        continue;
                    }
                    if (foo[0] == 'e' && foo[1] == 'x' && foo[2] == 'p') { //Если прочитанная функция - экспонента
                        item.type = 'e';
                        item.value = 0;
                        Stack_o.push(item);
                        continue;
                    }
                }
                if (Ch == 'p') { //Если прочитано число Пи
                    item.type = '0';
                    item.value = Pi;
                    Stack_n.push(item); 
                    flag = 0;
                    sstr.ignore();
                    continue;
                }
                if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag == 1) { //Если прочитано число
                    sstr >> value;
                    item.type = '0';
                    item.value = value;
                    Stack_n.push(item); 
                    flag = 0;
                    continue;
                }
                if (Ch == '+' || Ch == '-' && flag == 0 || Ch == '*' || Ch == '/' || Ch == '^') { //Если прочитана операция
                    if (Stack_o.size() == 0) { 
                        item.type = Ch;
                        item.value = 0;
                        Stack_o.push(item); 
                        sstr.ignore();
                        continue;
                    }
                    if (Stack_o.size() != 0 && getRang(Ch) >
                        getRang(Stack_o.top().type)) { 
                        item.type = Ch;
                        item.value = 0;
                        Stack_o.push(item);
                        sstr.ignore();
                        continue;
                    }
                    if (Stack_o.size() != 0 && getRang(Ch) <=
                        getRang(Stack_o.top().type)) {
                        if (Maths(Stack_n, Stack_o, item) == false) { 
                            system("pause");
                        }
                        continue;
                    }
                }
                if (Ch == '(') { //Если прочитана открывающаяся скобка
                    item.type = Ch;
                    item.value = 0;
                    Stack_o.push(item); 
                    sstr.ignore();
                    continue;
                }
                if (Ch == ')') { //Если прочитана закрывающаяся скобка
                    while (Stack_o.top().type != '(') {
                        if (Maths(Stack_n, Stack_o, item) == false) {
                            system("pause");
                        }
                        else continue; 
                    }
                    Stack_o.pop();
                    sstr.ignore();
                    continue;
                }
                else { 
                    /*cout << "\033[2J\033[H";*/
                    cout << "\nНеверно введено выражение, попробуйте еще раз или выйдите!";
                    Extended().ExtMain();
                    

                    
                }
            }
            while (Stack_o.size() != 0) {
                if (Maths(Stack_n, Stack_o, item) == false) { 
                    system("pause");
                }
                else continue;
            }
            cout << "   Ответ: " << Stack_n.top().value << endl;
            system("pause");
        }
    }




#pragma once
#include <vector>
#include <string>


class Menu {
private:
    //std::vector<std::string> history;
    void clear();
    void printResult(const std::string& operation, double result);
public:
    void showMenu();
    void run();
};

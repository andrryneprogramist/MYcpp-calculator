#include "AppCalculator.hpp"
#include <iostream>
int main()
{

    setlocale(LC_ALL, "Russian");

    AppCalculator::getInstance()->run(0, nullptr);
    return 0;
}
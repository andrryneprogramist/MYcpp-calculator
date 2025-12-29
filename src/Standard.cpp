#include <stdexcept>
#include "StandardMenu.h"
double add(double a, double b) {
    return a + b;
}
double substract(double a,double b) {
    return a - b;
}
double multiply(double a, double b) {
    return a * b;
}
double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}
double MyPower2(double a) {
    return a * a;
}
double reciprocal(double a) {
    if (a == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return 1 / a;
}
double squareroot(double a) {
    if (a < 0) {
        throw std::invalid_argument("SqrRoot of negative number");
    }
    double left = 0, right = a + 1;

    for (int i = 0; i < 20; i++) {
        double middle = (left + right) / 2;
        if (middle * middle < a) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return left;
}
double percent(double a, double b) { //a процентов от b
    return a * 0.01 * b;
}
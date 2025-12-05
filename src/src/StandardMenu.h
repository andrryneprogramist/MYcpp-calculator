#pragma once
double add(double a, double b);
double substract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double MyPower2(double a);
double reciprocal(double a);
double squareroot(double a);
double percent(double a, double b);

class StandartMenu {
private:
    // std::vector<std::string> history;

    void SMclear();

public:
    void showSMenu();
    void SMrun();
};
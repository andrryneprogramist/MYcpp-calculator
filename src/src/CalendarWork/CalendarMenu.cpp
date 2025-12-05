#include "CalendarMenu.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

void CalendarMenu::printCalendar() {
    int year;
    while (true)
    {
        std::cout << "------------------------------------------------" << std::endl;
        std::cout << "Enter a year or type anything else to quit: ";
        std::cin >> year;
        std::cout << "------------------------------------------------" << std::endl;
        if (std::cin.fail())
            break;
        int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        std::string monthList[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

        time_t ttime = time(0);
        // ÍÅÏÐÀÂÈËÜÍÎ - åñëè îáúÿâëåíî êàê:
        tm* local_time = localtime(&ttime);
        int current_year = 1900 + local_time->tm_year;
        int current_month = local_time->tm_mon + 1;
        int current_day = local_time->tm_mday;
        std::cout << " -----------------------------------" << std::endl;
        std::cout << "\033[1;33m"
            << "           Calendar - " << year
            << "\033[0m" << std::endl;
        std::cout << " -----------------------------------" << std::endl;

        int days;
        int startingGap;

        int tempY = year - 1;
        startingGap = (tempY + tempY / 4 - tempY / 100 + tempY / 400 + 1) % 7;

        for (int i = 0; i < 12; i++)
        {
            if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && i == 1)
                days = 29;
            else
                days = monthDays[i];

            std::cout << std::endl;
            if (year == current_year && current_month == i + 1)
            {
                std::cout << "\033[1;1;32m"
                    << "  ------------" << monthList[i] << "-------------"
                    << "\033[0m" << std::endl;
            }
            else if (year < current_year || (year == current_year && i + 1 < current_month))
            {
                std::cout << "\033[31m"
                    << "  ------------" << monthList[i] << "-------------"
                    << "\033[0m" << std::endl;
            }
            else
            {
                std::cout << "  ------------" << monthList[i] << "-------------"
                    << std::endl;
            }

            if (year < current_year || (year == current_year && i + 1 <= current_month))
            {
                std::cout << "\033[35m"
                    << "  Sun"
                    << "\033[0m";
                std::cout << "\033[1;33m"
                    << "  Mon  Tue  Wed  Thu  Frid";
                std::cout << "\033[35m"
                    << "  Sat"
                    << "\033[0m" << std::endl;
            }
            else
            {
                std::cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << std::endl;
            }
            int k;
            for (k = 0; k < startingGap; k++)
                std::cout << "     ";

            for (int j = 1; j <= days; j++)
            {
                k++;
                if (year == current_year && current_month == i + 1 && current_day == j)
                {
                    std::cout << "\033[1;1;32m" << std::setw(5) << j << "\033[0m";
                }
                else if (year < current_year || (year == current_year && i + 1 < current_month) || (year == current_year && i + 1 == current_month && j < current_day))
                {
                    std::cout << "\033[31m" << std::setw(5) << j << "\033[0m";
                }
                else
                {
                    std::cout << std::setw(5) << j;
                }
                if (k > 6)
                {
                    k = 0;
                    std::cout << std::endl;
                }
            }
            if (k)
                std::cout << std::endl;
            startingGap = k;
        }

    }
};
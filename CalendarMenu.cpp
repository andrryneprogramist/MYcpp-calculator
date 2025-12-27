#include "CalendarMenu.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <chrono>

void CalendarMenu::printCalendar() {
    int year;
        std::cout << "Введите год: ";
        std::cin >> year;
        int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        std::string monthList[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

        time_t ttime = time(0);
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

void CalendarMenu::timeToDate() {
    std::cout << "===Нахождение времени до даты===" << std::endl;
    std::cout << "Введите дату в виде: ДД ММ ГГГГ" << std::endl;
    int year, month, day;
    std::cin >> day >> month >> year;
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);

    std::tm targetTime = *now;
    targetTime.tm_year = year - 1900;
    targetTime.tm_mon = month - 1;
    targetTime.tm_mday = day;
    targetTime.tm_hour = 12;

    std::time_t now_seconds = std::mktime(now);
    std::time_t targetSeconds = std::mktime(&targetTime);

    double Diff = std::difftime(targetSeconds, now_seconds);
    int days = Diff / (24 * 60 * 60);
     
    if (days < 0) { std::cout << "Дата  " << day << "." << month << "." << year << " была " << -days << " Дня(ей) назад"<<std::endl;    system("pause"); }
    //if (static_cast<int>(days) == 0) { std::cout << "Дата " << day << "." << month << "." << year << " - Это сегодня!"; system("pause"); }
    if (days > 0) { std::cout << "Дата  " << day << "." << month << "." << year << " будет через " << days << " Дня(ей)" << std::endl; system("pause"); }
}

void CalendarMenu::CMclear() {
    std::cout << "\033[2J\033[H";
}

void CalendarMenu::showCMenu() {
    std::cout << "========== РАБОТА С ДАТАМИ ===========\n";
    std::cout << "1. Вывести календарь" << std::endl;
    std::cout << "2. Время до даты" << std::endl;
    std::cout << "3. День недели даты" << std::endl;
    std::cout << "4. Рассчет вашего возраста + времени до дня рождения)" << std::endl;
    std::cout << "0. Выход\n" << std::endl;
}

void CalendarMenu::Weekday() {
    std::cout << "===Нахождение я времени даты===" << std::endl;
    std::cout << "Введите дату в виде: ДД ММ ГГГГ" << std::endl;
    int day, month, year;
    std::cin >> day >> month >> year;   
        tm date = {};
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        mktime(&date);

        std::string days[] = { "Воскресенье", "Понедельник", "Вторник",
                              "Среда", "Четверг", "Пятница", "Суббота" };

        std::cout << "\n" << days[date.tm_wday];
    }
        
void CalendarMenu::date() {
    std::cout << "===Нахождение вашего точного возраста===" << std::endl;
    std::cout << "Введите дату в виде: ДД ММ ГГГГ" << std::endl;
    int day, month, year;
    std::cin >> day >> month >> year;
        time_t now = time(0);
        tm* today = localtime(&now);

        int currentYear = today->tm_year + 1900;
        int currentMonth = today->tm_mon + 1;
        int currentDay = today->tm_mday;

        int years = currentYear - year;
        int months = 0;
        int days = 0;

        if (currentMonth < month ||
            (currentMonth == month && currentDay < day)) {
            years--;
        }

        if (currentMonth >= month) {
            months = currentMonth - month;
            if (currentDay < day) {
                months--;
            }
        }
        else {
            months = 12 - (month - currentMonth);
            if (currentDay < day) {
                months--;
            }
        }

        if (currentDay >= day) {
            days = currentDay - day;
        }
        else {
            tm lastDayOfMonth = *today;
            lastDayOfMonth.tm_mday = 0;  
            mktime(&lastDayOfMonth);

            days = lastDayOfMonth.tm_mday - day + currentDay;
        }


        std::cout << "Возраст: " << years << " лет" << std::endl;

        if (months > 0 || days > 0) {
            std::cout <<"А если точнее, то " << years << " лет, " << months << " мес., " << days << " дн." << std::endl;
        }

        if (currentMonth == month && currentDay == day) {
            std::cout << "\n С ДНЕМ РОЖДЕНИЯ! " << std::endl;
            std::cout << "Вам сегодня исполняется " << years + 1 << " лет!" << std::endl;
        }
        else {
            tm nextBirthday = *today;
            nextBirthday.tm_year = currentYear - 1900;
            nextBirthday.tm_mon = month - 1;
            nextBirthday.tm_mday = day;

            if (currentMonth > month || (currentMonth == month && currentDay > day)) {
                nextBirthday.tm_year++;
            }

            mktime(&nextBirthday);

            double diff = difftime(mktime(&nextBirthday), now);
            int daysToBirthday = static_cast<int>(diff / (60 * 60 * 24));

            std::cout << "\nДо следующего дня рождения: " << daysToBirthday << " дней" << std::endl;
        }
    }


void CalendarMenu::runCM() {
    int choice;

    do {
        CalendarMenu CalendarMenu;
        std::cin >> choice;
        

        switch (choice) {
        case 1: {
            CalendarMenu.printCalendar();
            std::cout << "Выберите нужный вам режим или выйдите: ";
            break;
        }
        case 2: {
            CalendarMenu.timeToDate();
            std::cout << "Выберите нужный вам режим или выйдите: ";
            break;
            
        }
        case 3: {
            CalendarMenu.Weekday();
            std::cout << "Выберите нужный вам режим или выйдите: ";
            break;
            
        }
        case 4: {
            CalendarMenu.date();
            std::cout << "Выберите нужный вам режим или выйдите: ";
            break;
        }
        case 0: { // Выход
            CMclear();
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
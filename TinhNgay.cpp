#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include <fstream>
#include <iostream>

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            else
                return false;
        } else
            return true;
    } else
        return false;
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if (isLeapYear(year))
                return 29;
            else
                return 28;
        default:
            return 0;
    }
}

int main() {
    int day, month, year;

    // printf("Nhap vao ngay (dd mm yyyy): ");
    // scanf("%d %d %d", &day, &month, &year);

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the input file!\n";
        return 1;
    }
    if (!(inputFile >> day >> month >> year)) {
        std::cerr << "Error reading input from file!\n";
        return 1;
    }

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Kh�ng th? m? file d?u ra!\n";
        return 1;
    }

    if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
        printf("Ngay nhap vao khong hop le.\n");
        return 1;
    }

    int pDay = day, pMonth = month, pYear = year;
    int nDay = day, nMonth = month, nYear = year;

    nDay = day + 1;
    if (nDay > daysInMonth(month, year)) {
        nDay = 1;
        nMonth = month + 1;
        if (nMonth > 12) {
            nMonth = 1;
            nYear = year + 1;
        }
    }

    pDay = day - 1;
    if (pDay <= 0) {
        pMonth = month - 1;
        if (pMonth <= 0) {
            pMonth = 12;
            pYear = year - 1;
        }
        pDay = daysInMonth(pMonth, year);
    }

    // printf("Ngay hien tai: %02d/%02d/%04d\n", day, month, month);
    // printf("Ngay tiep theo: %02d/%02d/%04d\n", nDay, nMonth, nYear);
    // printf("Ngay truoc day: %02d/%02d/%04d\n", pDay, pMonth, pYear);

    outputFile << "Ngay hien tai:" << day << "/" << month << "/" << year
               << std::endl;
    outputFile << "Ngay tiep theo:" << nDay << "/" << nMonth << "/" << nYear
               << std::endl;
    outputFile << "Ngay truoc day:" << pDay << "/" << pMonth << "/" << pYear
               << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}

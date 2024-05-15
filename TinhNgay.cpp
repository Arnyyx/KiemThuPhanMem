#include <stdio.h>
#include <stdbool.h>

// Ki?m tra nam nhu?n
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

// S? ngày trong m?i tháng
int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (isLeapYear(year))
                return 29;
            else
                return 28;
        default:
            return 0; // Tháng không h?p l?
    }
}

int main() {
    int day, month, year;

    // Nh?p vào ngày, tháng, nam
    printf("Nhap vao ngay (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    // Ki?m tra ngày h?p l?
    if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
        printf("Ngay nhap vao khong hop le.\n");
        return 1;
    }

    // Tính ngày ti?p theo
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }

    // Hi?n th? ngày ti?p theo
    printf("Ngay tiep theo: %02d/%02d/%04d\n", day, month, year);

    return 0;
}


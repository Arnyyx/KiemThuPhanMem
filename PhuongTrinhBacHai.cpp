#include <math.h>
#include <stdio.h>

#include <fstream>
#include <iostream>

int main() {
    float a, b, c, delta, x1, x2;

    // printf("Nhap he so a: ");
    // scanf("%f", &a);

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the input file!\n";
        return 1;
    }
    if (!(inputFile >> a >> b >> c)) {
        std::cerr << "Error reading input from file!\n";
        return 1;
    }

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Kh�ng th? m? file d?u ra!\n";
        return 1;
    }

    if (a == 0) {
        // TH1: a = 0 => Phuong tr�nh b?c nh?t
        //    printf("Phuong trinh bac nhat.\n");
        // printf("Nhap he so b: ");
        // scanf("%f", &b);
        if (b == 0) {
            // TH1.1: a = b = 0 => V� nghi?m
            printf("Phuong trinh vo nghiem.\n");
            outputFile << "Phuong trinh vo nghiem" << std::endl;
        } else {
            // TH1.2: a = 0, b != 0 => C� 1 nghi?m
            // printf("Nhap he so c: ");
            // scanf("%f", &c);
            x1 = -c / b;
            printf("Nghiem duy nhat x = %f.\n", x1);
            outputFile << "Nghiem duy nhat x = " << x1 << std::endl;
        }
    } else {
        // TH2: a != 0 => Phuong tr�nh b?c hai
        // printf("Nhap he so b: ");
        // scanf("%f", &b);
        // printf("Nhap he so c: ");
        // scanf("%f", &c);

        delta = b * b - 4 * a * c;

        if (delta < 0) {
            // TH2.1: delta < 0 => V� nghi?m
            printf("Phuong trinh vo nghiem.\n");
            outputFile << "Phuong trinh vo nghiem" << std::endl;
        } else if (delta == 0) {
            // TH2.2: delta = 0 => C� 1 nghi?m k�p
            x1 = x2 = -b / (2 * a);
            printf("Nghiem kep x1 = x2 = %f.\n", x1);
            outputFile << "Nghiem kep x1 = x2 = " << x1 << std::endl;
        } else {
            // TH2.3: delta > 0 => C� 2 nghi?m ph�n bi?t
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Nghiem x1 = %f, x2 = %f.\n", x1, x2);
            outputFile << "Phuong trinh hai nghiem: x1 = " << x1
                       << " ; x2 = " << x2 << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
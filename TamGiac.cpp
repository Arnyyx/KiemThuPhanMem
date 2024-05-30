#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include <fstream>
#include <iostream>

float lamTron(float so, int soChuSoSauDauPhay) {
    if (soChuSoSauDauPhay < 0) {
        printf("So luong chu so sau dau phay phai lon hon hoac bang 0.\n");
        return so;
    }

    int phanNguyen = (int)so;
    float phanThapPhan = fmod(so, phanNguyen);
    float thapPhanSau = phanThapPhan * pow(10, soChuSoSauDauPhay);
    int thapPhanSauLamTron = round(thapPhanSau);
    thapPhanSau = thapPhanSauLamTron / pow(10, soChuSoSauDauPhay);
    float ketQua = phanNguyen + thapPhanSau;

    return ketQua;
}
bool isValidTriangle(float a, float b, float c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

bool isEquilateralTriangle(float a, float b, float c) {
    return (a == b) && (b == c);
}

bool isIsoscelesTriangle(float a, float b, float c) {
    return (a == b) || (a == c) || (b == c);
}

bool isRightTriangle(float a, float b, float c) {
    float a2 = a * a, b2 = b * b, c2 = c * c;
    return (fabs(a2 + b2 - c2) < 0.1) || (fabs(a2 + c2 - b2) < 0.1) ||
           (fabs(b2 + c2 - a2) < 0.1);
}

int main() {
    float a, b, c;

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

    // printf("Nhap vao 3 canh cua tam giac: ");
    // scanf("%f %f %f", &a, &b, &c);

    if (!isValidTriangle(a, b, c)) {
        printf("Day khong phai la mot tam giac.\n");
        outputFile << "Day khong phai la mot tam giac" << std::endl;
    } else {
        if (isEquilateralTriangle(a, b, c)) {
            printf("Day la tam giac deu.\n");
            outputFile << "Day la tam giac deu" << std::endl;
        } else if (isRightTriangle(a, b, c)) {
            if (isIsoscelesTriangle(a, b, c)) {
                printf("Day la tam giac vuong can.\n");
                outputFile << "Day la tam giac vuong can" << std::endl;
            } else {
                printf("Day la tam giac vuong.\n");
                outputFile << "Day la tam giac vuong" << std::endl;
            }
        } else if (isIsoscelesTriangle(a, b, c)) {
            printf("Day la tam giac can.\n");
            outputFile << "Day la tam giac vuong" << std::endl;
        } else {
            printf("Day la tam giac thuong.\n");
            outputFile << "Day la tam giac thuong" << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}

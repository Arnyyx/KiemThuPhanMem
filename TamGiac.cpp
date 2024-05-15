#include <stdio.h>
#include <stdbool.h>
#include <math.h>
float lamTron(float so, int soChuSoSauDauPhay) {
  // Ki?m tra s? lu?ng ch? s? sau d?u ph?y h?p l?
  if (soChuSoSauDauPhay < 0) {
    printf("So luong chu so sau dau phay phai lon hon hoac bang 0.\n");
    return so;
  }

  // Tách ph?n nguyên và ph?n th?p phân
  int phanNguyen = (int) so;
  float phanThapPhan = fmod(so, phanNguyen);

  // Nhân ph?n th?p phân v?i 10 mu s? ch? s? sau d?u ph?y
  float thapPhanSau = phanThapPhan * pow(10, soChuSoSauDauPhay);

  // Làm tròn ph?n th?p phân sau
  int thapPhanSauLamTron = round(thapPhanSau);

  // Chia ph?n th?p phân sau cho 10 mu s? ch? s? sau d?u ph?y
  thapPhanSau = thapPhanSauLamTron / pow(10, soChuSoSauDauPhay);

  // C?ng ph?n nguyên và ph?n th?p phân sau dã làm tròn
  float ketQua = phanNguyen + thapPhanSau;

  return ketQua;
}
// Hàm ki?m tra ba c?nh có t?o thành m?t tam giác h?p l? không
bool isValidTriangle(float a, float b, float c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Hàm ki?m tra tam giác d?u
bool isEquilateralTriangle(float a, float b, float c) {
    return (a == b) && (b == c);
}

// Hàm ki?m tra tam giác cân
bool isIsoscelesTriangle(float a, float b, float c) {
    return (a == b) || (a == c) || (b == c);
}

// Hàm ki?m tra tam giác vuông
bool isRightTriangle(float a, float b, float c) {
    float a2 = a * a, b2 = b * b, c2 = c * c;
    return (fabs(a2 + b2 - c2) < 0.1) || (fabs(a2 + c2 - b2) < 0.1) || (fabs(b2 + c2 - a2) < 0.1);
}

int main() {
    float a, b, c;
    
    // Nh?p vào 3 c?nh c?a tam giác
    printf("Nhap vao 3 canh cua tam giac: ");
    scanf("%f %f %f", &a, &b, &c);

    // Ki?m tra xem có ph?i là m?t tam giác h?p l? không
    if (!isValidTriangle(a, b, c)) {
        printf("Day khong phai la mot tam giac.\n");
    } else {
        // Ki?m tra lo?i tam giác
        if (isEquilateralTriangle(a, b, c)) {
            printf("Day la tam giac deu.\n");
        } else if (isRightTriangle(a, b, c)) {
            if (isIsoscelesTriangle(a, b, c)) {
                printf("Day la tam giac vuong can.\n");
            } else {
                printf("Day la tam giac vuong.\n");
            }
        } else if (isIsoscelesTriangle(a, b, c)) {
            printf("Day la tam giac can.\n");
        } else {
            printf("Day la tam giac thuong.\n");
        }
    }

    return 0;
}


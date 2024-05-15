#include <stdio.h>
#include <stdbool.h>
#include <math.h>
float lamTron(float so, int soChuSoSauDauPhay) {
  // Ki?m tra s? lu?ng ch? s? sau d?u ph?y h?p l?
  if (soChuSoSauDauPhay < 0) {
    printf("So luong chu so sau dau phay phai lon hon hoac bang 0.\n");
    return so;
  }

  // T�ch ph?n nguy�n v� ph?n th?p ph�n
  int phanNguyen = (int) so;
  float phanThapPhan = fmod(so, phanNguyen);

  // Nh�n ph?n th?p ph�n v?i 10 mu s? ch? s? sau d?u ph?y
  float thapPhanSau = phanThapPhan * pow(10, soChuSoSauDauPhay);

  // L�m tr�n ph?n th?p ph�n sau
  int thapPhanSauLamTron = round(thapPhanSau);

  // Chia ph?n th?p ph�n sau cho 10 mu s? ch? s? sau d?u ph?y
  thapPhanSau = thapPhanSauLamTron / pow(10, soChuSoSauDauPhay);

  // C?ng ph?n nguy�n v� ph?n th?p ph�n sau d� l�m tr�n
  float ketQua = phanNguyen + thapPhanSau;

  return ketQua;
}
// H�m ki?m tra ba c?nh c� t?o th�nh m?t tam gi�c h?p l? kh�ng
bool isValidTriangle(float a, float b, float c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// H�m ki?m tra tam gi�c d?u
bool isEquilateralTriangle(float a, float b, float c) {
    return (a == b) && (b == c);
}

// H�m ki?m tra tam gi�c c�n
bool isIsoscelesTriangle(float a, float b, float c) {
    return (a == b) || (a == c) || (b == c);
}

// H�m ki?m tra tam gi�c vu�ng
bool isRightTriangle(float a, float b, float c) {
    float a2 = a * a, b2 = b * b, c2 = c * c;
    return (fabs(a2 + b2 - c2) < 0.1) || (fabs(a2 + c2 - b2) < 0.1) || (fabs(b2 + c2 - a2) < 0.1);
}

int main() {
    float a, b, c;
    
    // Nh?p v�o 3 c?nh c?a tam gi�c
    printf("Nhap vao 3 canh cua tam giac: ");
    scanf("%f %f %f", &a, &b, &c);

    // Ki?m tra xem c� ph?i l� m?t tam gi�c h?p l? kh�ng
    if (!isValidTriangle(a, b, c)) {
        printf("Day khong phai la mot tam giac.\n");
    } else {
        // Ki?m tra lo?i tam gi�c
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


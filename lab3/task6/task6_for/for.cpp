#include <iostream>
using namespace std;

double sum(int n) {
    double sum1 = 0;
    for (int i = 0; i < n; ++i) {
        sum1 += pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
    }
    return sum1;
}

double sum2(double eps) {
    double sum1 = 0;
    for (int i = 0; ; i++) {
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        if (abs(sum1) < eps) break;
    }
    return sum1;
}

void print(int n, int k) {
    double sum1 = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (i % k == k - 1) continue;
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        printf("Иттерация: %d ", i + 1);
        printf(" Результат: %f\n", sum1);
    }
}

int findFirstElement(double eps) {
    int k;
    double sum1 = 0;
    for (int i = 0; ; i++) {
        k = i;
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        if (abs(sum1) < eps) break;
    }
    return k;
}

int findFirstNegativeElement(double eps) {
    int k;
    double sum1 = 0;
    for (int i = 0; ; i++) {
        k = i;
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        if (sum1 > 0) continue;
        if (abs(sum1) <= eps) {
            return k;
        }
    }
}
#include <iostream>
using namespace std;

double sum(int n) {
    double sum1 = 0;
    int i = 0;
    do {
        sum1 += pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        i++;
    } while (i < n);
    return sum1;
}

double sum2(double eps) {
    int i = 0;
    double sum1 = 0;
    do {
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        i++;
    } while (abs(sum1) > eps);
    return sum1;
}

void print(int n, int k) {
    int i = 0;
    double sum1 = 0;
    do {
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        i++;
        if (i % k == 0)	continue;
        printf("Иттерация: %d ", i);
        printf(" Результат: %f\n", sum1);
    } while (i < n);
}

int findFirstElement(double eps) {
    int i = 0;
    int k = 0;
    double sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
    do {
        if (abs(sum1) <= eps) break;
        i++;
        k = i;
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
    } while (true);
    return k;
}

int findFirstNegativeElement(double eps) {
    int i = 0;
    int k = 0;
    double sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
    do {
        i++;
        k = i;
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        if (sum1 > 0) continue;
        if (abs(sum1) <= eps) {
            return k;
        }
    } while (true);
}
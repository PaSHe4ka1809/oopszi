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
        sum1 += pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        i++;
    } while (abs(sum1) >= eps);
    return sum1;
}

void print(int n, int k) {
    int i = 0;
    double sum1 = 0;
    do {
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        i++;
        if (i % k == 0) continue;
        cout << sum1 << endl;
    } while (i < n);

}
int findFirstElement(double eps) {
    int i = 0;
    int k = 0;
    double sum1 = 0;
    do {
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        k = i;
        i++;
    } while (abs(sum1) >= eps);
    return k;
}

int findFirstNegativeElement(double eps) {
    int i = 0;
    int k = 0;
    double sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
    do {
        i++;
        sum1 = pow(-1, i) * (pow(2, i + 1) / (pow(2, 2 * i) + 1));
        if (sum1 > 0) continue;
        k = i;
    } while (abs(sum1) >= eps);
    return k;
}
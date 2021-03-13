#include <iostream>
#include "do.h"
using namespace std;

int main() {
    char key;
    double eps;
    int n, k, restart;
    for (;;) {
        setlocale(LC_ALL, "RUS");
        system("cls");
        cout << "1. Задание 1\n2. Задание 2\n3. Задание 3\n4. Задание 4\n5. Задание 5\n6. Выход\n";
        cin >> key;
        switch (key) {
        case '1': {
            system("cls");
            cout << "n: ";
            cin >> n;
            cout << "Результат: " << sum(n) << endl;
            break;
        }
        case '2': {
            system("cls");
            cout << "eps: ";
            cin >> eps;
            cout << "Результат: " << sum2(eps) << endl;
            break;
        }
        case '3': {
            system("cls");
            cout << "n: ";
            cin >> n;
            cout << "k: ";
            cin >> k;
            cout << "Результат: " << endl;
            print(n, k);
            break;
        }
        case '4': {
            system("cls");
            cout << "eps: ";
            cin >> eps;
            cout << "Результат: " << findFirstElement(eps) << endl;
            break;
        }
        case '5': {
            system("cls");
            cout << "eps: ";
            cin >> eps;
            cout << "Результат: " << findFirstNegativeElement(eps) << endl;
            break;
        }
        case '6': {
            system("cls");
            exit(0);
            break;
        }
        default: {
            break;
        }

        }
        system("pause");
    }
}
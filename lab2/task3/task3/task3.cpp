#include <iostream>
using namespace std;

char key;
double x, y, res, task;
bool result;

char func(char key) {
    switch (key) {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    default:
        cout << "Неверный ввод\n";
        return key;
        break;
    }
}

bool IsInArea(double x, double y) {
    if (x * x + y * y < 1) return true;
    else if ((x >= -1) && (x <= 0) && (y <= 1) && (y >= -1)) return true;
    else return false;
}

double f(double x) {
    if (x <= 3) return x * x + 3 * x + 9;
    else return 1 / (x * x * x + 6);
}

void main() {
    setlocale(LC_ALL, "RUS");
    cout << "Выберите нужное задание:\n1. Задание 1\n2. Задание 2" << endl;
    cin >> key;
    task = func(key);
    if (task == 1) {
        printf("Задание 1\n");
        bool IsInArea(double x, double y);
        cout << "x:";
        cin >> x;
        cout << "y:";
        cin >> y;
        result = IsInArea(x, y);
        if (result == true) cout << "Точка находится в закрашенной области\n";
        else cout << "Точка НЕ находится в закрашенной области\n";
    }
    else if (task == 2) {
        printf("Задание 2\n");
        double f(double x);
        cout << "x=";
        cin >> x;
        res = f(x);
        cout << "f(x)=" << res << endl;
    }
    system("pause");
}

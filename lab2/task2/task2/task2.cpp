#include <iostream>;
using namespace std;

double f(double x) {
    if (x <= 3) return x * x + 3 * x + 9;
    else return 1 / (x * x * x + 6);
}

void main(void) {
    double x, res;
    cout << "x=";
    cin >> x;
    res = f(x);
    cout << "f(x)=" << res << endl;
    system("pause");
}

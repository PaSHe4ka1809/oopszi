#include <iostream>;
using namespace std;

double f(double x) {
    x <= 3? x = x * x + 3 * x + 9 : x = 1 / (x * x * x + 6);
    return x;
}

void main(void) {
    double x, res;
    cout << "x=";
    cin >> x;
    res = f(x);
    cout << "f(x)=" << res << endl;
    system("pause");
}

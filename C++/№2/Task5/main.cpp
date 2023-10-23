#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow((pow(x, 2) + 4 * sin(x) + 1), 2);
}

double fd(double x) {
    return 2 * (pow((pow(x, 2) + 4 * sin(x) + 1), 2)) * (2 * x + 4 * cos(x));
}

double bisectionMethod(double a, double b, double eps, double f(double)) {
    double x1, x2;
    while (abs(b - a) > eps) {
        x1 = a + 0.25 * (b - a);
        x2 = a + 0.75 * (b - a);
        if (f(x1) < f(x2)) b = x2; else a = x1;
    }
    return (a + b) * 0.5;
}

double goldenSectionMethod(double a, double b, double eps, double f(double)) {
    const double phi = (1 + sqrt(5)) / 2;
    double x1 = b - (b - a) / phi;
    double x2 = a + (b - a) / phi;
    while (abs(b - a) > eps) {
        if (f(x1) < f(x2)) {
            b = x2;
            x2 = x1;
            x1 = b - (b - a) / phi;
        } else {
            a = x1;
            x1 = x2;
            x2 = a + (b - a) / phi;
        }
    }
    return (a + b) / 2;
}


int main() {
    double a, b, eps;
    double x;
    cout << "Writeln [a, b] and E from f: ";
    cin >> a >> b >> eps;
    x = bisectionMethod(a, b, eps, f);
    cout << "Bisection => x = " << x << " y'(x) = " << fd(x) << endl;
    x = goldenSectionMethod(a, b, eps, f);
    cout << "Golden = > x = " << x << " y'(x) = " << fd(x) << endl;
    return 0;
}
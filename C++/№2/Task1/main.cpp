#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 2) + 4 * sin(x) + 1;
}

double fd(double x) {
    return 2 * x + 4 * cos(x);
}

double halfDivision(double (*f)(double), double a, double b, double eps) {
    double c;
    while ((b - a) / 2 > eps) {
        c = (a + b) / 2;
        if (f(a) * f(c) > 0) a = c;
        else b = c;
    }
    return c;
}

double tangent(double (*f)(double), double x0, double eps) {
    double x = x0;
    double fx = f(x);
    double dfx = fd(x);
    while (abs(fx) > eps) {
        x = x - fx / dfx;
        fx = f(x);
        dfx = fd(x);
    }
    return x;
}

double chord(double a, double b, double eps) {
    double x0, x1;
    do {
        x0 = a - (f(a) * (b - a)) / (f(b) - f(a));
        x1 = x0 - (f(x0) * (b - a)) / (f(b) - f(a));
        if (f(x1) * f(a) < 0) {
            b = x1;
        } else {
            a = x1;
        }
    } while (abs(x1 - x0) > eps);
    return x1;
}


int main() {
    double a, b, eps;
    double x;
    cout << "Writeln [a, b] and E from f: ";
    cin >> a >> b >> eps;
    x = halfDivision(f, a, b, eps);
    cout << "Half Division x = " << x << "; y(x) = " << f(x) << endl;
    x = tangent(f, a, eps);
    cout << "Tangent x = " << x << "; y(x) = " << f(x) << endl;
    x = chord(a, b, eps);
    cout << "Chord x = " << x << "; y(x) = " << f(x) << endl;
    return 0;
}

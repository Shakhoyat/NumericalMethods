#include <iostream>
#include <cmath>

using namespace std;

double f(double x0, double y0) {
    return 7 * x0 - 8 * y0;
}

double exact_solution(double x) {
    // Assuming the exact solution is known and is given by some function g(x)
    // Replace this with the actual exact solution if known
    return 7*x/8 +71/64*exp(-8*x) -7/64; // Example exact solution
}

int main() {
    double h = 0.1, x0 = 0, y0 =-7/64 , st = 0, en = 10;
    int iteration = 0;
    cout << "i\tx\tRK4_y\tExact_y\tAbs_diff" << endl;
    while (st <= en) {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * f(x0 + h, y0 + k3);
        double y1 = y0 + (double)(1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        double exact_y = exact_solution(x0);
cout << iteration << "\t" << x0 << "\t" << y0 << "\t" << exact_y << "\t" << abs(exact_y - y0) << endl;
                x0 = x0 + h;
        y0 = y1;
        st = st + h;
        iteration++;
    }
    return 0;
}
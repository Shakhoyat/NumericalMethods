/**
 * @file numericalInteg.cpp
 * @brief Numerical integration methods: Trapezoidal Rule, Simpson's 1/3 Rule, and Simpson's 3/8 Rule.
 * 
 * This file contains implementations of three numerical integration methods:
 * - Trapezoidal Rule
 * - Simpson's 1/3 Rule
 * - Simpson's 3/8 Rule
 * 
 * Each method has its own advantages and is suitable for different scenarios:
 * 
 * - Trapezoidal Rule:
 *   - Suitable for a quick and simple approximation.
 *   - Works well with any number of points.
 *   - Less accurate compared to Simpson's rules, especially for functions that are not linear.
 * 
 * - Simpson's 1/3 Rule:
 *   - Provides higher accuracy than the Trapezoidal Rule for smooth functions.
 *   - Requires an odd number of points (even number of intervals).
 *   - Ideal for functions that can be approximated well by parabolas over each interval.
 * 
 * - Simpson's 3/8 Rule:
 *   - Provides higher accuracy than the Trapezoidal Rule and is comparable to Simpson's 1/3 Rule.
 *   - Requires the number of intervals to be a multiple of 3.
 *   - Suitable for functions that can be approximated well by cubic polynomials over each interval.
 * 
 * Example usage:
 * - Define the function to be integrated.
 * - Create vectors of x and y values.
 * - Call the desired integration method with the x and y vectors.
 * 
 * Note: Ensure the input vectors x and y are of the same size and correspond to the function values at the given points.
 */
#include <iostream>
#include <vector>
#include <cmath>

// Function to be integrated
double f(double x) {
    return sin(x); // Example function
}
using namespace std;
// Trapezoidal Rule
double trapezoidalRule(const vector<double>& x, const vector<double>& y) {
    double integral = 0.0;
    for (size_t i = 0; i < x.size() - 1; ++i) {
        integral += 0.5 * (x[i+1] - x[i]) * (y[i] + y[i+1]);
    }
    return integral;
}

// Simpson's 1/3 Rule
double simpsonsOneThirdRule(const vector<double>& x, const vector<double>& y) {
    if (x.size() % 2 == 0) {
        cerr << "Simpson's 1/3 rule requires an odd number of points." << endl;
        return 0.0;
    }
    double integral = y[0] + y.back();
    for (size_t i = 1; i < x.size() - 1; ++i) {
        if (i % 2 == 0) {
            integral += 2 * y[i];
        } else {
            integral += 4 * y[i];
        }
    }
    integral *= (x[1] - x[0]) / 3.0;
    return integral;
}

// Simpson's 3/8 Rule
double simpsonsThreeEighthRule(const vector<double>& x, const vector<double>& y) {
    if ((x.size() - 1) % 3 != 0) {
        cerr << "Simpson's 3/8 rule requires the number of intervals to be a multiple of 3." << endl;
        return 0.0;
    }
    double integral = y[0] + y.back();
    for (size_t i = 1; i < x.size() - 1; ++i) {
        if (i % 3 == 0) {
            integral += 2 * y[i];
        } else {
            integral += 3 * y[i];
        }
    }
    integral *= 3 * (x[1] - x[0]) / 8.0;
    return integral;
}

int main() {
    // Example usage
    vector<double> x = {0, M_PI/4, M_PI/2, 3*M_PI/4, M_PI};
    vector<double> y(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        y[i] = f(x[i]);
    }

    cout << "Trapezoidal Rule: " << trapezoidalRule(x, y) << endl;
    cout << "Simpson's 1/3 Rule: " << simpsonsOneThirdRule(x, y) << endl;
    cout << "Simpson's 3/8 Rule: " << simpsonsThreeEighthRule(x, y) << endl;

    return 0;
}
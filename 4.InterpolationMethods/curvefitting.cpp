#include <iostream>
#include <vector>
#include <cmath>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

// Function to perform a straight-line fit using the least-squares method
void straightLineFit(const vector<double>& x, const vector<double>& y) {
    int n = x.size(); // Number of data points
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    // Compute sums required for straight-line fit
    for (int i = 0; i < n; ++i) {
        sumX += x[i];               // Sum of x values
        sumY += y[i];               // Sum of y values
        sumXY += x[i] * y[i];       // Sum of x * y
        sumX2 += x[i] * x[i];       // Sum of x^2
    }

    // Calculate slope (b) and intercept (a) for the line y = a + bx
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;

    // Output the straight-line equation
    cout << "Straight Line Fit: y = " << a << " + " << b << "x" << endl;
}

// Function to perform polynomial fitting of a given degree
void polynomialFit(const vector<double>& x, const vector<double>& y, int degree) {
    int n = x.size(); // Number of data points
    MatrixXd A(n, degree + 1); // Matrix for polynomial terms
    VectorXd B(n);            // Vector for y values

    // Fill the matrix A with powers of x and vector B with y values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= degree; ++j) {
            A(i, j) = pow(x[i], j); // x^j
        }
        B(i) = y[i]; // y value at index i
    }

    // Solve the system of equations A * coeffs = B to find polynomial coefficients
    VectorXd coeffs = A.colPivHouseholderQr().solve(B);

    // Output the polynomial equation
    cout << "Polynomial Fit: y = ";
    for (int i = 0; i <= degree; ++i) {
        cout << coeffs[i]; // Coefficient of x^i
        if (i > 0) cout << "x^" << i; // Append x^i for higher powers
        if (i < degree) cout << " + "; // Add "+" between terms
    }
    cout << endl;
}

// Function to perform a transcendental fit of the form y = a * e^(bx)
void transcendentalFit(const vector<double>& x, const vector<double>& y) {
    int n = x.size(); // Number of data points
    double sumX = 0, sumLogY = 0, sumXLogY = 0, sumX2 = 0;

    // Compute sums required for the transformation log(y) = log(a) + bx
    for (int i = 0; i < n; ++i) {
        sumX += x[i];               // Sum of x values
        sumLogY += log(y[i]);       // Sum of log(y) values
        sumXLogY += x[i] * log(y[i]); // Sum of x * log(y)
        sumX2 += x[i] * x[i];       // Sum of x^2
    }

    // Calculate the slope (b) and intercept (logA) of the transformed equation
    double b = (n * sumXLogY - sumX * sumLogY) / (n * sumX2 - sumX * sumX);
    double logA = (sumLogY - b * sumX) / n;
    double a = exp(logA); // Back-transform to find a

    // Output the transcendental equation
    cout << "Transcendental Fit: y = " << a << " * e^(" << b << "x)" << endl;
}

int main() {
    // Input data points (x, y)
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2.3, 2.9, 3.8, 4.5, 5.1};

    // Perform different fits on the data
    straightLineFit(x, y);           // Straight-line fit
    polynomialFit(x, y, 2);          // Polynomial fit of degree 2
    transcendentalFit(x, y);         // Transcendental fit

    return 0;
}

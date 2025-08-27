#include <iostream>
#include <vector>
#include <iomanip> // For std::setprecision
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if (n == 0) return 1; // Handle factorial of 0
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to calculate forward differences
void forwardDifferences(vector<double>& y, vector<vector<double>>& diffTable, int n) {
    for (int i = 0; i < n; ++i) {
        diffTable[0][i] = y[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            diffTable[i][j] = diffTable[i - 1][j + 1] - diffTable[i - 1][j];
        }
    }
}

// Function for numerical differentiation using Newton's forward difference interpolation
double numericalDifferentiation(vector<vector<double>>& diffTable, int n, double h, double u) {
    double derivative = 0.0; // Initialize derivative

    // First-order term
    if (n > 1) {
        derivative += diffTable[1][0]; // First forward difference
    }

    // Higher-order terms
    double u_term = 1.0; // Reset u_term for higher-order terms
    for (int i = 2; i < n; ++i) {
        u_term *= (u - (i - 1)); // Update u_term for current order
        derivative += (u_term * diffTable[i][0]) / factorial(i);
    }

    return derivative / h; // Divide by h as per formula
}

int main() {
    int n;
    double h, x0, x;

    // Input the number of data points
    cout << "Enter the number of data points (max 6): ";
    cin >> n;

    if (n < 1 || n > 6) {
        cout << "Invalid number of data points. Please enter a value between 1 and 6." << endl;
        return 1;
    }

    // Example data points
    vector<double> xValues = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0}; // x values
    vector<double> yValues = {3.375, 7.0, 13.625, 24.0, 38.875, 59.0}; // y values

    // Create forward difference table
    vector<vector<double>> diffTable(n, vector<double>(n, 0));
    forwardDifferences(yValues, diffTable, n);

    // Set x0 (initial point)
    x0 = xValues[0];

    // Input the x where derivative is to be found
    cout << "Enter the x where derivative is to be found: ";
    cin >> x;

    // Check if x is within bounds
    if (x < xValues[0] || x > xValues[n - 1]) {
        cout << "x is out of bounds. Please enter a value between " << xValues[0] << " and " << xValues[n - 1] << "." << endl;
        return 1;
    }

    h = xValues[1] - xValues[0]; // Assumes equal interval
    double u = (x - x0) / h;

    // Calculate the derivative
    double derivative = numericalDifferentiation(diffTable, n, h, u);

    // Output the result with fixed precision
    cout << fixed << setprecision(6);
    cout << "The derivative at x = " << x << " is: " << derivative << endl;

    return 0;
}

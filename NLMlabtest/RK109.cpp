#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Function f(x, y) representing the ODE dy/dx = 7x - 8y
double f(double x, double y) { return (2 * x + 3 * y); }

double analytical_solution(double x) {
  const double C = (8 + (2.0 / 9.0) * exp(-3 * 2)) /
                   exp(3 * 2); // Calculating C from y(2) = 8
  return -2.0 / 3.0 * x - 2.0 / 9.0 + C * exp(3 * x);
}

// Function to calculate and print y-values using Runge-Kutta method and
// analytical method
void Y_val() {
  double x0 = 2, y0 = 8, error_sum = 0; // Initial conditions and error sum
  double rng = 6, h = 0.2;              // Range of x values and step size
  int itr = 1;                          // Iteration counter

  // Loop over the range of x values from 0 to 6
  while (rng >= x0) {
    // Runge-Kutta method (4th order) for solving the ODE
    double k1 = h * f(x0, y0);
    double k2 = h * f(x0 + h / 2, y0 + k1 / 2);
    double k3 = h * f(x0 + h / 2, y0 + k2 / 2);
    double k4 = h * f(x0 + h, y0 + k3);

    // Update the value of y using the weighted average of k1, k2, k3, and k4
    y0 = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;

    // Calculate the absolute error between the analytical solution and runge
    // kutta solution
    double abs_error = fabs(analytical_solution(x0) - y0);

    // Print the current iteration, x-value, analytical y-value, numerical
    // y-value, and absolute error
    cout << setw(5) << itr++ << setw(10) << fixed << setprecision(2) << x0
         << setw(15) << fixed << setprecision(6) << analytical_solution(x0)
         << setw(15) << fixed << setprecision(6) << y0 << setw(15) << fixed
         << setprecision(6) << abs_error << endl;

    // Accumulate the error for calculating the average later
    error_sum += abs_error;
    // Increment the value of x
    x0 += h;
  }

  // Calculate and print the average error
  double avg_error = error_sum / itr;
  cout << "Average error: " << avg_error << endl;
}

int main() {
  Y_val();  // Call the function to solve the ODE and print the results
  return 0; // End of program
}
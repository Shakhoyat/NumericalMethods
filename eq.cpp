///Fitting a second degree parabola
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    vector <float> x = {0,1,2,3,4};
//    vector <float> y = {1,1.8,1.3,2.5,6,3};
//    //calcuating the sum of x, y, x^2, x^3, x^4, x*y, x^2*y
//    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_xy = 0, sum_x2y = 0;
//    for (int i = 0; i < x.size(); i++)
//    {
//        sum_x += x[i];
//        sum_y += y[i];
//        sum_x2 += x[i] * x[i];
//        sum_x3 += x[i] * x[i] * x[i];
//        sum_x4 += x[i] * x[i] * x[i] * x[i];
//        sum_xy += x[i] * y[i];
//        sum_x2y += x[i] * x[i] * y[i];
//    }
//    //solving the equations
//    float a0, a1, a2;
//    a0 = (sum_y * sum_x2 * sum_x2 - sum_x * sum_x2 * sum_xy + sum_x * sum_x * sum_x2y) / (x.size() * sum_x2 * sum_x2 - sum_x * sum_x * sum_x);
//    a1 = (x.size() * sum_x2y - sum_x * sum_xy) / (x.size() * sum_x2 - sum_x * sum_x);
//    a2 = (sum_xy - sum_x * a1) / sum_x2;
//    cout << "The equation of the parabola is: y = " << a2 << "x^2 + " << a1 << "x + " << a0 << endl;
//    //calculating new y values
//    vector <float> y_new;
//    for (int i = 0; i < x.size(); i++)
//    {
//        y_new.push_back(a2 * x[i] * x[i] + a1 * x[i] + a0);
//    }
//    return 0;
//
//}
//
///quadratic eqn y=a +bx + cx2
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//    vector<float> x = {1, 2, 3, 4, 5};
//    vector<float> y = {.5, 2, 4.5, 8, 12.5};
//
//    // Converting y values to log(y)
//    vector<float> log_y;
//    for (auto& val : y) {
//        log_y.push_back(log(val));
//    }
//
//    // Compute sums for linear regression
//    float sum_x = 0, sum_log_y = 0, sum_x2 = 0, sum_x_log_y = 0;
//    int n = x.size();
//
//    for (int i = 0; i < n; ++i) {
//        sum_x += x[i];
//        sum_log_y += log_y[i];
//        sum_x2 += x[i] * x[i];
//        sum_x_log_y += x[i] * log_y[i];
//    }
//
//    // Linear regression on log_y = log(a) + x * log(b)
//    float log_b = (n * sum_x_log_y - sum_x * sum_log_y) / (n * sum_x2 - sum_x * sum_x);
//    float log_a = (sum_log_y - log_b * sum_x) / n;
//
//    // Convert log(a) and log(b) back to a and b
//    float a = exp(log_a);
//    float b = exp(log_b);
//
//    cout << "The equation of the form y = ab^x is: y = " << a << " * " << b << "^x" << endl;
//
//    return 0;
//}
//
//
//
///fitting a curve of the form y = mx+c
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    vector<float> x = {1, 2, 3, 4, 5};
//    vector<float> y = {2, 3, 5, 7, 9};
//
//    // Compute sums for linear regression
//    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
//    int n = x.size();
//
//    for (int i = 0; i < n; ++i)
//    {
//        sum_x += x[i];
//        sum_y += y[i];
//        sum_x2 += x[i] * x[i];
//        sum_xy += x[i] * y[i];
//    }
//
//    // Linear regression on y = mx + c
//    float m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
//    float c = (sum_y - m * sum_x) / n;
//
//    cout << "The equation of the form y = mx + c is: y = " << m << "x + " << c << endl;
//
//    return 0;
//}

///thik thak ase merged1 with errors but not prediction

//#include <bits/stdc++.h>
//
//using namespace std;
//
//// Function to calculate mean error
//float calculateMeanError(const vector<float>& observed, const vector<float>& predicted) {
//    float sum_error = 0;
//    for (size_t i = 0; i < observed.size(); ++i) {
//        sum_error += fabs(observed[i] - predicted[i]); // Absolute difference
//    }
//    return sum_error / observed.size();
//}
//
//// Function to fit a linear line (y = mx + c)
//float fitLinear(const vector<float>& x, const vector<float>& y, vector<float>& predicted_y) {
//    int n = x.size();
//    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
//
//    for (int i = 0; i < n; ++i) {
//        sum_x += x[i];
//        sum_y += y[i];
//        sum_x2 += x[i] * x[i];
//        sum_xy += x[i] * y[i];
//    }
//
//    float m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
//    float c = (sum_y - m * sum_x) / n;
//
//    // Calculate predicted y values
//    predicted_y.clear();
//    for (int i = 0; i < n; ++i) {
//        predicted_y.push_back(m * x[i] + c);
//    }
//
//    cout << "Linear Fit: y = " << m << "x + " << c << endl;
//    return calculateMeanError(y, predicted_y);
//}
//
//// Function to fit a quadratic line (y = a + bx + cx^2)
//float fitQuadratic(const vector<float>& x, const vector<float>& y, vector<float>& predicted_y) {
//    int n = x.size();
//    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_xy = 0, sum_x2y = 0;
//
//    for (int i = 0; i < n; ++i) {
//        sum_x += x[i];
//        sum_y += y[i];
//        sum_x2 += x[i] * x[i];
//        sum_x3 += x[i] * x[i] * x[i];
//        sum_x4 += x[i] * x[i] * x[i] * x[i];
//        sum_xy += x[i] * y[i];
//        sum_x2y += x[i] * x[i] * y[i];
//    }
//
//    // Solve the normal equations
//    float D = n * (sum_x2 * sum_x4 - sum_x3 * sum_x3) -
//              sum_x * (sum_x * sum_x4 - sum_x2 * sum_x3) +
//              sum_x2 * (sum_x * sum_x3 - sum_x2 * sum_x2);
//
//    float A = sum_y * (sum_x2 * sum_x4 - sum_x3 * sum_x3) -
//              sum_x * (sum_xy * sum_x4 - sum_x2y * sum_x3) +
//              sum_x2 * (sum_xy * sum_x3 - sum_x2y * sum_x2);
//
//    float B = n * (sum_xy * sum_x4 - sum_x2y * sum_x3) -
//              sum_y * (sum_x * sum_x4 - sum_x2 * sum_x3) +
//              sum_x2 * (sum_x * sum_x2y - sum_x2 * sum_xy);
//
//    float C = n * (sum_x2 * sum_x2y - sum_xy * sum_x3) -
//              sum_x * (sum_x * sum_x2y - sum_x2 * sum_xy) +
//              sum_y * (sum_x * sum_x3 - sum_x2 * sum_x2);
//
//    float a = A / D;
//    float b = B / D;
//    float c = C / D;
//
//    // Calculate predicted y values
//    predicted_y.clear();
//    for (int i = 0; i < n; ++i) {
//        predicted_y.push_back(a + b * x[i] + c * x[i] * x[i]);
//    }
//
//    cout << "Quadratic Fit: y = " << a << " + " << b << "x + " << c << "x^2" << endl;
//    return calculateMeanError(y, predicted_y);
//}
//
//// Function to fit an exponential line (y = ab^x)
//float fitExponential(const vector<float>& x, const vector<float>& y, vector<float>& predicted_y) {
//    int n = x.size();
//    float sum_x = 0, sum_log_y = 0, sum_x2 = 0, sum_x_log_y = 0;
//
//    for (int i = 0; i < n; ++i) {
//        if (y[i] <= 0) {
//            cout << "Error: Exponential fit requires all y > 0." << endl;
//            return numeric_limits<float>::max(); // Return a large value if invalid
//        }
//        float log_y = log(y[i]);
//        sum_x += x[i];
//        sum_log_y += log_y;
//        sum_x2 += x[i] * x[i];
//        sum_x_log_y += x[i] * log_y;
//    }
//
//    float log_b = (n * sum_x_log_y - sum_x * sum_log_y) / (n * sum_x2 - sum_x * sum_x);
//    float log_a = (sum_log_y - log_b * sum_x) / n;
//
//    float a = exp(log_a);
//    float b = exp(log_b);
//
//    // Calculate predicted y values
//    predicted_y.clear();
//    for (int i = 0; i < n; ++i) {
//        predicted_y.push_back(a * pow(b, x[i]));
//    }
//
//    cout << "Exponential Fit: y = " << a << " * " << b << "^x" << endl;
//    return calculateMeanError(y, predicted_y);
//}
//
//int main() {
//    vector<float> x = {-5,-3,-1,1,3,8};
//    vector<float> y = {16,27,23,21,18,13};
//
//    vector<float> predicted_y;
//    float linearError = fitLinear(x, y, predicted_y);
//    float quadraticError = fitQuadratic(x, y, predicted_y);
//    float exponentialError = fitExponential(x, y, predicted_y);
//
//    cout << "\nMean Errors:" << endl;
//    cout << "Linear Fit Error: " << linearError << endl;
//    cout << "Quadratic Fit Error: " << quadraticError << endl;
//    cout << "Exponential Fit Error: " << exponentialError << endl;
//
//    // Determine the best fit
//    if (linearError < quadraticError && linearError < exponentialError) {
//        cout << "The best fit is: Linear" << endl;
//    } else if (quadraticError < linearError && quadraticError < exponentialError) {
//        cout << "The best fit is: Quadratic" << endl;
//    } else {
//        cout << "The best fit is: Exponential" << endl;
//    }
//
//    return 0;
//}
//

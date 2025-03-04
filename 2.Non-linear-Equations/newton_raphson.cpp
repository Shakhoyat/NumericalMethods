#include <bits/stdc++.h>
using namespace std;

double func_value(const vector<double> &v1, double x) {
    double sum = 0.0;
    for (int i = 0; i < v1.size(); i++) {
        sum += v1[i] * pow(x, v1.size() - i - 1);
    }
    return sum;
}

vector<double> derivative(const vector<double> &v) {
    int n = v.size();
    vector<double> diff(n - 1);
    for (int i = 0; i < n - 1; i++) {
        diff[i] = v[i] * (n - i - 1);
    }
    return diff;
}

void synthetic_division(vector<double> &poly, double root) {
    int n = poly.size();
    cout << "Incoming poly : ";
    for(auto i : poly){
        cout << i << " ";
    }
    cout << endl;
    vector<double> new_poly(n - 1);
    new_poly[0] = poly[0];
    for (int i = 1; i < n - 1; i++) {
        new_poly[i] = poly[i] + new_poly[i - 1] * root;
    }
    poly = new_poly;
    cout << "Outgoing poly : ";
    for(auto i : poly){
        cout << i << " ";
    }
    cout << endl;
}

double newton_method(vector<double> &v, vector<double> &dv, double tol, int max_iter) {
    double x = 1.0, next_x;
    for (int i = 1; i <= max_iter; i++) {
        double f_x = func_value(v, x);
        double f_dx = func_value(dv, x);
        if (fabs(f_dx) < tol) {
            cout << "Derivative too small, stopping Newton iteration." << endl;
            break;
        }
        next_x = x - f_x / f_dx;
        if (fabs(func_value(v, next_x)) < tol){
            cout << "Root : " << next_x << endl;
            return next_x;
        }
        x = next_x;
    }
    return x;
}

void find_all_roots(){
    int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;
    vector<double> v(n + 1);
    cout << "Enter the coefficients of the polynomial (from highest to lowest degree): ";
    for (int i = 0; i <= n; i++){
        cin >> v[i];
    }
    double tol = 1e-10;
    int max_iter = 100;
    cout << "Finding all roots using Newton's Method:" << endl;
    while (v.size() > 1) {
        vector<double> dv = derivative(v);
        double root = newton_method(v, dv, tol, max_iter);
        synthetic_division(v, root);
        cout << endl;
    }
}

int main() {
    find_all_roots();    
    return 0;
}
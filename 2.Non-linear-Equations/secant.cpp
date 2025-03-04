#include<bits/stdc++.h>
using namespace std;

double func_value(const vector<double> &v1, double x) {
    double sum = 0.0;
    for (int i = 0; i < v1.size(); i++) {
        sum += v1[i] * pow(x, v1.size() - i - 1);
    }
    return sum;
}

void synthetic_division(vector<double> &poly, double root) {
    int n = poly.size();
    vector<double> new_poly(n - 1);
    new_poly[0] = poly[0];
    for (int i = 1; i < n - 1; i++) {
        new_poly[i] = poly[i] + new_poly[i - 1] * root;
    }
    poly = new_poly;
}

double secant_method(vector<double> &v, double tol, int max_iter) {
    double a = 1.0, b = 10.0, c;
    for (int i = 1; i <= max_iter; i++) {
        double f_a = func_value(v, a);
        double f_b = func_value(v, b);
        if(fabs(f_b - f_a) < tol){
            break;
        }
        c = b - f_b * (b - a) / (f_b - f_a);
        double f_c = func_value(v, c);
        
        if (fabs(f_c) < tol) {
            cout << "Secant Method Root: " << c << endl;
            return c;
        }
        a = b;
        b = c;
    }
    return c;
}

void find_all_roots() {
    int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;
    vector<double> v(n + 1);
    
    cout << "Enter the coefficients (highest degree first): ";
    for (int i = 0; i <= n; i++){
        cin >> v[i];
    } 
    
    double tol = 1e-10;
    int max_iter = 100;
    
    cout << "Finding all roots using Secant Method:" << endl;
    while (v.size() > 1) {
        double root = secant_method(v, tol, max_iter);
        synthetic_division(v, root);
        cout << endl;
    }
}

int main() {    
    find_all_roots();
    return 0;
}
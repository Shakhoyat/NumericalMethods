#include<bits/stdc++.h>
using namespace std;

//Lagrange interpolation is generally used when:
//1.Non-uniformly Spaced Data Points: The data points are not evenly spaced.
//2.Small Number of Data Points: The number of data points is relatively small, as Lagrange interpolation can become computationally expensive with a large number of points.
//3.Polynomial Interpolation: You need a polynomial that passes through all given data points.

double lagrangeInterpolation(const vector<double>xvals,const vector<double>yvals,double x){
    double res=0;
    int n=xvals.size();
    for(int i=0;i<n;i++){
        double term=yvals[i];
            for(int j=0;j<n;j++){
                if(j!=i){
                    term*=(x-xvals[j])/(xvals[i]-xvals[j]);
                }
            }
            res+=term;
    }
    return res;
}

// Function to calculate the forward differences
vector<vector<double>> forwardDifferences(const vector<double>& yvals) {
    int n = yvals.size();
    vector<vector<double>> diffTable(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = yvals[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
    return diffTable;
}

// Function to calculate the backward differences
vector<vector<double>> backwardDifferences(const vector<double>& yvals) {
    int n = yvals.size();
    vector<vector<double>> diffTable(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = yvals[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
        }
    }
    return diffTable;
}

// Newtonian Forward Interpolation
//Use this method when the target value is closer to the beginning of the data points.

double newtonianForwardInterpolation(const vector<double>& xvals, const vector<double>& yvals, double x) {
    int n = xvals.size();
    vector<vector<double>> diffTable = forwardDifferences(yvals);
    double h = xvals[1] - xvals[0];
    double s = (x - xvals[0]) / h;
    double result = yvals[0];
    double term = 1;
    for (int i = 1; i < n; i++) {
        term *= (s - (i - 1)) / i;
        result += term * diffTable[0][i];
    }
    return result;
}

// Newtonian Backward Interpolation
//Use this method when the target value is closer to the end of the data points.

double newtonianBackwardInterpolation(const vector<double>& xvals, const vector<double>& yvals, double x) {
    int n = xvals.size();
    vector<vector<double>> diffTable = backwardDifferences(yvals);
    double h = xvals[1] - xvals[0];
    double s = (x - xvals[n - 1]) / h;
    double result = yvals[n - 1];
    double term = 1;
    for (int i = 1; i < n; i++) {
        term *= (s + (i - 1)) / i;
        result += term * diffTable[n - 1][i];
    }
    return result;
}

int main(){
    vector<double>xvals={10,20,30,40,50};
    vector<double>yvals={0.1736,0.3420,0.5,0.6428,0.7660};
    double target;cout<<"Enter the target\n";
    cin>>target;

    // Choose interpolation method based on the target value
    double ans;
    if (target <= xvals[xvals.size() / 2]) {
        ans = newtonianForwardInterpolation(xvals, yvals, target);
    } else {
        ans = newtonianBackwardInterpolation(xvals, yvals, target);
    }

    cout<<"Ans="<<ans<<endl;
}
//forward o better  result dibe,bt backward e kom accurate value dibe...implement the left 2 methods
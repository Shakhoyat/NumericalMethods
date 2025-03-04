#include<bits/stdc++.h>
using namespace std; 

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
int main(){
    vector<double>xvals={1,2,3,4,5};
    vector<double>yvals={ 3.25,3.05,3.5,3.75,4.00};
    double target;
    cout<<"Enter the target semester's numerical value : ";
    cin>>target;
    double ans=newtonianForwardInterpolation(xvals,yvals,target);
    cout<<"The final CGPA after midterm of 2-2 will be = "<<ans<<endl;

}
#include<bits/stdc++.h>
using namespace std;

vector<vector<double>>table (vector<double>yvals)
{
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

double forwordfunc(vector<double>x,vector<double>y,double xx)
{
    int n=x.size();
    vector<vector<double>>tab=table(y);
    double h=x[1]-x[0];
    double s=(xx-x[0])/h;
    double res=y[0];
    double term=1;
    for(int i=1;i<n;i++)
    {
        term*=(s-(i-1))/i;
        res+=term*tab[0][i];
    }
    return res;
}

void forwardDifferenceTable(vector<double>& y, vector<vector<double>>& diffTable, int n) {
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
}

double derivative(vector<double> x, vector<double> y, int n, double xp) {
    for (int i = 1; i < n; i++) {
        if (x[i - 1] <= xp && xp <= x[i]) {
            return (y[i] - y[i - 1]) / (x[i] - x[i - 1]);
        }
    }
    return 0.0;
}
int main()
{
    int n;
    n=5;
    vector<double>x(n),y(n);
    double xx;
    cin>>xx;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>y[j];
    }

    cout<<"expected : "<<forwordfunc(x,y,xx)<<endl;
    double h = x[1] - x[0];
    vector<vector<double>> forwardDiffTable(n, vector<double>(n, 0.0));
    forwardDifferenceTable(y, forwardDiffTable, n);
     cout << "Tangent : " <<derivative(x,y,n,forwordfunc(x,y,xx))<< endl;
    return 0;
}


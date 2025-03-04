#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double fn(double x,vector<double>&coefficient) {
double result=0.0;
int deg=coefficient.size() - 1;
    for (int i = 0; i <= deg; i++) {
        result+=coefficient[i]*pow(x,deg - i);
    }
    return result;
}


void false_Position(double a, double b, double tolerence, vector<double>&roots,int&it_count,vector<double>&coefficient) {
    if (fn(a,coefficient)*fn(b, coefficient)>=0) {
        return;
    }

double c;
it_count = 0;
while(true){
        c = b - (fn(b, coefficient) * (a - b)) / (fn(a, coefficient) - fn(b, coefficient)); // False position formula
        it_count++;

if (fabs(fn(c, coefficient)) < tolerence || fabs(b - a) < tolerence)
{
            roots.push_back(c);
            return;
}


if (fn(c,coefficient)*fn(a,coefficient) < 0){
            b = c;
        } else {
            a = c;
    }
  }
}

void All_roots(double start,double ending,double step,double tolerence,vector<double>&coefficient) {
vector<double> roots;
vector<int> iterations;
    for(double i=start;i<ending;i+=step) {
        int it_count = 0;
        if(fn(i,coefficient)*fn(i+step,coefficient)<0) {
            false_Position(i,i+step,tolerence,roots,it_count,coefficient);
            if(it_count>0) {
                iterations.push_back(it_count);
            }
        }
    }

    for (size_t j=0;j<roots.size();++j) {
        cout << "Root " << j+1 << " = " << roots[j] << endl;
    }
cout<<endl;
}

int main() {
int deg;
cout << "Enter the deg of the polynomial: ";
cin >> deg;

vector<double> coefficient(deg + 1);
cout << "Enter the coefficient highest to lowest order : ";
    for(int i=0; i<=deg;i++){
        cin>>coefficient[i];
    }
double xmax,a,b,c;
a = coefficient[1]/coefficient[0];
b = coefficient[2]/coefficient[0];
c = (a * a) - (2 * b);
xmax = abs(sqrt(c));
double start = -xmax;
double ending = xmax;

double step = 0.01;
double tolerence = 1e-6;

    All_roots(start,ending,step,tolerence,coefficient);

return 0;
}
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//make polynomial
double f(double x,vector<double>&coefficients) {
double res=0.0;
int deg=coefficients.size()-1;
    for(int i=0;i<=deg;i++)
        {
       res+=coefficients[i]*pow(x,deg-i);
    }
return res;
}

void bisection(double a,double b,double tolerence,vector<double>&roots,int&it_count,vector<double>&coefficients)
{
    if(f(a,coefficients)*f(b,coefficients)>=0) {
        return;
    }

double c;
it_count=0;
    while((b-a)/2.0>tolerence){
        it_count++;
        c=(a+b)/2.0;
    if(f(c,coefficients)==0.0) {
            roots.push_back(c);
            return;
        }
    if(f(a,coefficients)*f(c,coefficients)<0) {
            b=c;
        }
    else{
            a=c;
        }
    }
    roots.push_back((a+b)/2.0);
}


void all_roots(double start,double ending,double step,double tolerence,vector<double>&coefficients)
{
vector<double> roots;
vector<int> iterations;
    for(double i=start;i<ending;i+=step) {
        int it_count = 0;
        if(f(i,coefficients)*f(i+step,coefficients) < 0) {
            bisection(i, i + step, tolerence, roots, it_count, coefficients);
            if (it_count > 0) {
                iterations.push_back(it_count); // Store the count if a root was found
            }
        }
    }

    // Output found roots and their iteration counts
    for (size_t j=0;j<roots.size();++j) {
        cout << "Root " << j+1 << " = " << roots[j] << endl;
    }
    cout<<endl;
}

int main() {
int deg;
cout<<"Enter the deg of the polynomial: ";
cin>>deg;

vector<double>coefficient(deg+1);
cout << "Enter the coefficients from highest to lowest(x^3,x^2...)\n";
    for (int i=0;i<=deg;i++) {
        cin >>coefficient[i];
    }

double xmax,a,b,c;
a = coefficient[1]/coefficient[0];
b = coefficient[2]/coefficient[0];
c = (a * a) - (2 * b);
xmax = abs(sqrt(c));
double start = -xmax;
double ending = xmax;

double step=0.01;
double tolerence=1e-6;

    all_roots(start,ending,step,tolerence,coefficient);

return 0;
}


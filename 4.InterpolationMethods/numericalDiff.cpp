#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the forward difference table
void forwardDifferenceTable(vector<double> &y,
                            vector<vector<double>> &diffTable, int n) {
  for (int i = 0; i < n; i++) {
    diffTable[i][0] = y[i];
  }
  for (int j = 1; j < n; j++) {
    for (int i = 0; i < n - j; i++) {
      diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
    }
  }
}

// Function to calculate the backward difference table
void backwardDifferenceTable(vector<double> &y,
                             vector<vector<double>> &diffTable, int n) {
  for (int i = 0; i < n; i++) {
    diffTable[i][0] = y[i];
  }
  for (int j = 1; j < n; j++) {
    for (int i = n - 1; i >= j; i--) {
      diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
    }
  }
}

// Function to calculate the first order derivative using Newton's forward
// interpolation
double firstOrderForward(vector<double> &x, vector<vector<double>> &diffTable,
                         double h, int n) {
  return (diffTable[0][1] / h);
}

// Function to calculate the first order derivative using Newton's backward
// interpolation
double firstOrderBackward(vector<double> &x, vector<vector<double>> &diffTable,
                          double h, int n) {
  return (diffTable[n - 1][1] / h);
}

// Function to calculate the second order derivative using Newton's forward
// interpolation
double secondOrderForward(vector<double> &x, vector<vector<double>> &diffTable,
                          double h, int n) {
  return (diffTable[0][2] / (h * h));
}

// Function to calculate the second order derivative using Newton's backward
// interpolation
double secondOrderBackward(vector<double> &x, vector<vector<double>> &diffTable,
                           double h, int n) {
  return (diffTable[n - 1][2] / (h * h));
}

int main() {
  int n;
  cout << "Enter the number of data points: ";
  cin >> n;

  vector<double> x(n), y(n);
  cout << "Enter the data points (x and y):\n";
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  double h = x[1] - x[0];
  vector<vector<double>> forwardDiffTable(n, vector<double>(n, 0.0));
  vector<vector<double>> backwardDiffTable(n, vector<double>(n, 0.0));

  forwardDifferenceTable(y, forwardDiffTable, n);
  backwardDifferenceTable(y, backwardDiffTable, n);

  cout << "First order derivative using Newton's forward interpolation: "
       << firstOrderForward(x, forwardDiffTable, h, n) << endl;
  cout << "First order derivative using Newton's backward interpolation: "
       << firstOrderBackward(x, backwardDiffTable, h, n) << endl;
  cout << "Second order derivative using Newton's forward interpolation: "
       << secondOrderForward(x, forwardDiffTable, h, n) << endl;
  cout << "Second order derivative using Newton's backward interpolation: "
       << secondOrderBackward(x, backwardDiffTable, h, n) << endl;

  return 0;
}
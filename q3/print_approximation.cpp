#include "series.hpp"
#include "function.hpp"
#include <iostream>

using namespace std;

int main (int argc, char** argv) {
  SeriesConstant(5);

  double x = 1; //value of x at which to evaluate the function.
  int max_n = 20;

  if (argc > 2) {
    x = stod(argv[1]);
    max_n = stoi(argv[2]);
  } else if (argc > 1) {
    x = stod(argv[1]);
  }

  double prev; //prev is a_n x^n
  if (b.a(0) != 0) {
    prev = Series::a(0);
  } else {
    prev = 1;
  }
  double prevcoeff;
  int prevempty;

  for (int i=0 ; i < max_n; i++) {

    if (Series::a(i) == 0) {
      prevempty = i;
      prev = prev*x; //use the previous coefficient but multiply it by x;
    } else {
      prevcoeff = Series::a(i-1);

      if (prevcoeff == 0) { //if previous coefficient is 0
        prevcoeff = Series::a(prevempty-1)
      }

      prev = prev * Series::a(i)/prevcoeff * x; //increment
    }

    cout << i << "," << Series::evaluate_truncated(x,i) << "," << a(i) << "," << prev << endl;
  }

}

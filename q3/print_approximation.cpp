#include "series.hpp"
#include "series_operations.hpp"
#include "function.hpp"
#include <iostream>

using namespace std;

int main (int argc, char** argv) {
  
  ///////////////////DEFINITIONS///////////////////
  Series *s;
  double x = 1; //value of x at which to evaluate the function.
  int max_n = 20;

  ///////////////////TAKING INPUT ARGUMENTS///////////////////
  if (argc > 3) { //take in expression, x and max
    s = series_parse(argv[1]);
    x = stod(argv[2]);
    max_n = stoi(argv[3]);
  } else if (argc > 1) { //take in only expression and x.
    s = series_parse(argv[1]);
    x = stod(argv[1]);
  } else if (argc >0) { //take in only exression
    s = series_parse(argv[1]);
  } else {
    cerr << "no expression taken" << endl;
    exit(1);
  }

  double prev; //prev is a_n x^n
  if (s->a(0) != 0) {
    prev = s->a(0);
  } else {
    prev = 1;
  }
  double prevcoeff;
  int prevempty;

  for (int i=0 ; i < max_n; i++) {

    if (s->a(i) == 0) {
      prevempty = i;
      prev = prev*x; //use the previous coefficient but multiply it by x;
    } else {
      prevcoeff = s->a(i-1);

      if (prevcoeff == 0) { //if previous coefficient is 0
        prevcoeff = s->a(prevempty-1);
      }

      prev = prev * s->a(i)/prevcoeff * x; //increment
    }

    ////////////////////OUTPUTS////////////////////
    cout << i << "," << s->evaluate_truncated(x,i) << "," << s->a(i) << "," << prev << endl;
  }

}

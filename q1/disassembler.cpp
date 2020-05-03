#include "mu0.hpp"
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main () {

  uint16_t instr;
  string instruction;

  while (cin) {
    cin >> hex >> instr;
    instruction = mu0_disassemble_instruction(instr);
    cout << instruction << endl;
  }
    

}

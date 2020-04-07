#include "mu0.hpp"
#include <iostream>
using namespace std;

int main () {
  uint16_t instr;
  cin >> hex >> instr;
  cout << mu0_disassemble_instruction(instr);
}

#include "mu0.hpp"
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

string gen_random_string() {
    string res = "";

    static const char alpha[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i=0; i<3; i++) { //3 characters (capital and small case) more than sufficient for 4096 locations.
        res = res + alpha[rand() % 3];
    }

    return res;
}

int twoscomplementtosigneddec(uint16_t binary) {
    int pwr = pow(2,15);
    int acc = 0;
    int selector = 15;

    for (int i=0; i<16; ++i)
    {
        if ( i==0 && ((binary >> selector) & 1) !=0 ) {
            acc = pwr * -1; //top bit is negatively weighted.
        } else  {
            acc += (((binary >> selector) & 1))* pwr;
        }
        pwr /= 2;
        selector = selector -1;
    }
    return acc;
}

int main () {
  
  //////////////////// MEMORY INSERTION ////////////////////
  vector<uint16_t> memory;
  while (cin) {
    memory = mu0_read_binary(cin); 
  }

  //////////////////// PROCESSING ////////////////////
  string assem;
  uint16_t instr;
  uint16_t opcode;
  uint16_t opout;
  uint16_t opbits{0x0FFF}; //operand is lower 12 bits.

  bool past_stop = false;
  int constant;

  string res;
  string label;
  map<uint16_t, string> label_map;
  map<int, string> out_map;

  for (int i=0; i<memory.size(); i++) {

    if (mu0_disassemble_instruction(memory[i]) == "STP") {
      past_stop = true;
      out_map.insert({i,"STP"});
    }

    if (!past_stop) {
      assem = mu0_disassemble_instruction(memory[i]);
      while (assem.size()>3) {
        assem.pop_back();
      }

      opcode = memory[i] >> 12;

      if (mu0_instruction_has_operand(opcode)) {
        instr = memory[i];
        opout = instr & opbits;      

        //generate random string only if the address has not been used before
        if (label_map.find(opout) == label_map.end()) { //this address has not been used before.
          label = gen_random_string(); //generate random string.
          label_map.insert({opout,label});
        } else { //address has been used before, use string in map instead.
          label = label_map.find(opout)->second;
        }

        res = assem + " " + label;
        out_map.insert({i, res});
        
      } else {
        out_map.insert({i, assem}); //only asm (STP, INP, OUT instruction)
      }

    } else { //past stop: all content is constants rather than instructions.
      constant = twoscomplementtosigneddec(memory[i]);
      out_map.insert({i, to_string(constant)});
    }

    assem.clear();
    label.clear();
    res.clear();
  }

  ////////////////////OUTPUTS ////////////////////
  uint16_t out_address;
  string out_label;
  string out_instr;
  string out_res;

  for (int i=0; i<memory.size(); i++) {
    out_address = i;
    if (out_map.find(i) == out_map.end()) { // end of prints
      exit;
    } else {
      out_instr = out_map.find(i)->second;
      if (label_map.find(out_address) == label_map.end()) { //this location is not labelled.
        out_res = "   " + out_instr;
      } else { //labeled location: print with label.
        out_label = label_map.find(out_address)->second;
        out_res = out_label + ": " + out_instr;
      }
    }

    cout << out_res << endl;
  }
}

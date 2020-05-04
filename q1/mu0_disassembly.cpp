#include "mu0.hpp"

#include <sstream>
#include <cassert>
#include <iostream>
#include <cmath>

bool mu0_is_instruction(uint16_t v)
{
    return (v>>12) < 10;
}

string mu0_disassemble_instruction(uint16_t instr)
{
    bool op3 = (instr >> 15) & 1;
    bool op2 = (instr >> 14) & 1;
    bool op1 = (instr >> 13) & 1;
    bool op0 = (instr >> 12) & 1;
    uint16_t opbits{0x0FFF}; //operand is lower 12 bits.
    uint16_t opout = instr & opbits;
    string operand = " " + to_string(opout);

    if (op3) { //INP, OUT
        if (op2 || op1) { //invalid
          //int invalid = twoscomplementtosigneddec(instr);
          //return to_string(invalid);
        }
        if (op0) { //OUT
          return "OUT";
        } else { //INP
          return "INP";
        }
    } else { //LDA STA ADD SUB JMP JGE JNE STP
      if (op2) { //JMP, JGE, JNE, STP
        if (op1) {//JNE, STP
          if (op0) { // STP
            return "STP";
          } else { // JNE
            return "JNE" + operand;
          }
        } else { // JMP, JGE
          if (op0) { //JGE
              return "JGE" + operand;
          } else { //JMP
              return "JMP" + operand;
          }
        }
      } else {
        if (op1) { //ADD, SUB
          if (op0) { //SUB
            return "SUB" + operand;
          } else { //ADD
            return "ADD" + operand;
          }
        } else { //STA, LDA
          if (op0) { // STA
            return "STA" + operand;
          } else { //LDA
            return "LDA" + operand;
          }
        }
      }
    }

}

string mu0_opcode_to_opname(uint16_t opcode)
{
    const vector<string> opnames={
        "LDA", "STA", "ADD", "SUB", "JMP", "JGE", "JNE", "STP", "INP", "OUT"
    };
    return opnames.at(opcode);
}

// Returns true if the given opcode has a memory operand
bool mu0_instruction_has_operand(uint16_t opcode)
{
    assert(opcode < 10);
    return opcode < 7;
}

vector<uint16_t> mu0_read_binary(std::istream &src)
{
    vector<uint16_t> memory;

    int num = 1;
    string line;

    while( getline(src, line) ){
        assert(num <= 4096);

        if (line.empty()) {
          break;
        }

        // Trim initial space
        while(line.size()>0 && isspace(line.front())){
            line = line.substr(1); // Remove first characters
        }

        // Trim trailing space
        while(line.size()>0 && isspace(line.back())){
            line.pop_back();
        }

        if(line.size()!=4){
            cerr<<"Line "<<num<<" : expected exactly four chars, got '"<<line<<'"'<<endl;
            exit(1);
        }
        for(int i=0; i<line.size(); i++){
            if(!isxdigit(line[i])){
                cerr<<"Line "<<num<<" : expected only hexadecimal digits, got '"<<line[i]<<'"'<<endl;
                exit(1);
            }
        }

        unsigned x=stoul(line, nullptr, 16);
        assert(x<65536);
        memory.push_back(x);

        num++;
    }
    memory.resize(num-1, 0);

    return memory;
}

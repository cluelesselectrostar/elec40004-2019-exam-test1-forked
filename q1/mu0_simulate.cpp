#include "mu0.hpp"

#include <cassert>

int16_t mu0_simulate(uint16_t *memory) //memory contents modified in place; returned array is final state of CPU memory
{
	int16_t acc;
	for(int pc=0; pc<4096; pc++){
		string inst = to_string(memory[pc]);
		if(inst[0] == '0'){ //LDA
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
		acc = memory[stoi(opr)];
		} 
		if(inst[0] == '1'){ //STA
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
		memory[stoi(opr)] = acc;
		}
		if(inst[0] == '2'){ //ADD
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
		acc = acc + memory[stoi(opr)];
		}
		if(inst[0] == '3'){ //SUB
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
		acc = acc - memory[stoi(opr)];
		}
		if(inst[0] == '4'){ //JMP
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
			pc = stoi(opr);
		}
		if(inst[0] == '5'){ //JGE
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
			if(acc>=0){
				pc = stoi(opr);
			}
		}
		if(inst[0] == '6'){ //JNE
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
			if(acc!=0){
				pc = stoi(opr);
			}
		}
		if(inst[0] == '7'){ //return when STP instruction is executed. Return value is final value of ACC.
			return acc;
			break;
		}
		if(inst[0] == '8'){ //INP via mu0_input not cin
			acc = mu0_input();
		}
		if(inst[0] == '9'){ //OUT via mu0_output not cout
			mu0_output(acc);
		}
	}
}

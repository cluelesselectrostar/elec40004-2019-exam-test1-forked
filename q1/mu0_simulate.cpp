#include "mu0.hpp"

#include <cassert>

int16_t mu0_simulate(uint16_t *memory)
{
	int16_t acc;
	for(int pc=0; pc<4096; pc++){
		string inst = to_string(memory[pc]);
		if(inst[0] == '0'){
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
		acc = memory[stoi(opr)];
		} 
		if(inst[0] == '1'){
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
		memory[stoi(opr)] = acc;
		}
		if(inst[0] == '2'){
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
		acc = acc + memory[stoi(opr)];
		}
		if(inst[0] == '3'){
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
		acc = acc - memory[stoi(opr)];
		}
		if(inst[0] == '4'){
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
			pc = stoi(opr);
		}
		if(inst[0] == '5'){
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
			if(acc>=0){
				pc = stoi(opr);
			}
		}
		if(inst[0] == '6'){
			string opr;
			for(int i=3; i>0; i--){
				opr.push_back(inst[i]);
			}
			if(acc!=0){
				pc = stoi(opr);
			}
		}
		if(inst[0] == '7'){
			return acc;
			break;
		}
		if(inst[0] == '8'){
			acc = mu0_input();
		}
		if(inst[0] == '9'){
			mu0_output(acc);
		}
	}
}

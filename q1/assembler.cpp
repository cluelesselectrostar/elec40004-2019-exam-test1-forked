#include "mu0.hpp"
#include <iostream>

using namespace std;

int main()
{
	string inp;
	string opc;
	string opr;
	vector<string> printer;
	while(1){
		cin >> inp;
		if(cin.fail()){
			break;
		}
		if(mu0_is_instruction(inp)){
			if(inp=="LDA"){
				opc="0";
			}
			if(inp=="STA"){
				opc="1";
			}
			if(inp=="ADD"){
				opc="2";
			}
			if(inp=="SUB"){
				opc="3";
			}
			if(inp=="JMP"){
				opc="4";
			}
			if(inp=="JGE"){
				opc="5";
			}
			if(inp=="JNE"){
				opc="6";
			}
			if(inp=="STP"){
				opc="7";
				opr="000";
			}
			if(inp=="INP"){
				opc="8";
				opr="000";
			}
			if(inp=="OUT"){
				opc="9";
				opr="000";
			}
		}
		if(mu0_is_data(inp)){
			opr=inp;
		}
		if(!opc.empty() && !opr.empty()){
			string tmp = opc + opr;			
			printer.push_back(tmp);
		}
	}
			
	for(int i=0; i<printer.size(); i++){
		cout << printer[i] << endl;
	}
}

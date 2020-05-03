#include "mu0.hpp"
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

struct instruction {
	int address;
	string label;
	string content; //need to translate operand to hex during cout.

	void clear() {
		address = 0;
		label.clear();
		content.clear();
	}
};

string op_convert(const string &inp) {
	string opc;
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
				//opr="000";
			}
			if(inp=="INP"){
				opc="8";
				//opr="000";
			}
			if(inp=="OUT"){
				opc="9";
				//opr="000";
			}
	return opc;
}

string signed_dec_to_hex (int num, int digits) {
	stringstream ss; 
    ss << hex << num; 
    string res = ss.str(); 
	while (res.size() < digits) {
		res.insert(0,"0");
	}
	return res;
}

int main()
{
	string inp;
	instruction current;
	vector<instruction> prog;
	int i=0;

	string opcode;
	string operand;
	string content;

	map<string, int> label_map;

	string out;

	while(1){
		cin >> inp;
		cerr << "input taken" << endl;

		if(cin.fail()){
			break;
		}

		/*
		2 cases:
		1) label + content
		2) content (instruction + label/data)
		*/

		current.address = i;

		if(mu0_is_label_decl(inp)) { // case 1: label + content

			inp.pop_back();
			current.label = inp;
			cin >> inp;

			if(mu0_is_data(inp)) {
				current.content = signed_dec_to_hex(stoi(inp),4);
				cerr << "inserted data of label" << endl;
			} else {

			}
			
			label_map.insert({current.label, current.address});
			cerr << "inserted label into map" << endl;

		} else if(mu0_is_instruction(inp)){ //case 2: opcode + (and) label/data

			opcode = op_convert(inp);
			cerr << "opcode taken " << opcode << endl;

			if (opcode == "7" || opcode == "8" || opcode == "9") { //no operand for STP, INP, OUT;
				current.content = opcode + "000";
			} else {
				cin >> inp;

				if(mu0_is_data(inp)){
					operand = signed_dec_to_hex(stoi(inp),3);
					current.content = opcode + operand;
					cerr << "opcode + operand " << current.content << endl;
				} else {
					current.content = opcode + inp; //content is now operand + label	
					cerr << "label taken" << endl;
				}
			
			}

		} else {
			exit(1);
		}

		prog.push_back(current);
		cerr << "inserted into vector prog." << endl;
		current.clear();
		i+=1;
	}

	cerr << "all inputs taken" << endl << endl;

	//print map to cerr 
	cerr << "print map" << endl;
	for (auto it = label_map.cbegin(); it != label_map.cend(); ++it) {
		cerr << it->first << " " << it->second << endl;
	}

	//now print and match maps.
	for (int i=0; i<prog.size(); i++) {
		cerr << "output " << prog[i].content << endl;
		out = prog[i].content;
		if (!isdigit(out[2])) {
			string tag = out;
			tag.erase(0,1);
			cerr << "erased opcode " << tag << endl;

			string tag_match;
			if (label_map.find(tag) == label_map.end()) {
				cerr << "label does not exist." << endl;
			} else {
				tag_match = label_map.find(tag)->second;
				while (tag_match.size()>3) {
					tag_match.erase(0,1);
				}
			}
			
			out = out[1] + tag_match;
		}
		cout << out << endl;
	}
			
	
}

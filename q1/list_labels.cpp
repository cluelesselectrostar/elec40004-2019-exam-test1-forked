#include "mu0.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	/*
	
	I somehow think we interpreted this incorrectly.
	What if the label comes before the instruction?

	LDA TEN
	Z: OUT //what about this?
	ADD NEG_ONE
	JNE Z
	Y: STP
	TEN: 10
	NEG_ONE: -1

	*/

	string s;
	vector<string> printer;
	while(1){
		cin >> s;
		if(cin.fail()){
			break;
		}
		if(mu0_is_label_decl(s)){
			string tmp;
			for(int j=0; j<s.length()-1; j++){
				tmp.push_back(s[j]);
			}
				printer.push_back(tmp);
		}
	}
	sort(printer.begin(), printer.end());
	//cout << printer.size() << endl;
	for(int i=0; i<printer.size(); i++){
		cout << printer[i] << endl;
	}
}
	

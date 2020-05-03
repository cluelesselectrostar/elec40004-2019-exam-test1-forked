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
	vector<string> prints;

	while (cin >> s) {

		if (cin.fail()) {
			break;
		}

		if (s.empty()) {
			break;
		}

		if (s.back() == ':') {
			s.pop_back();
			prints.push_back(s);
			s.clear();
		}

	}

	sort(prints.begin(), prints.end());

	for (int i=0; i<prints.size(); i++) {
		cout << prints[i] << endl;
	}

}
	

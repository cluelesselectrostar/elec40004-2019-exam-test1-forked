#include "mu0.hpp"

#include <iostream>
#include <cctype>
#include <cassert>

using namespace std;

int main()
{
	string label1 = "TEN:";
	string label2 = "NEG_ONE:";
	//string label3;
	string label4 = "p";

	string data1 = "10";
	string data2 = "-20";
	//string data3;
	string data4 = "lol";

	cout << mu0_is_label_decl(label1) << mu0_is_label_decl(label2) /*<< mu0_is_label_decl(label3) */<< mu0_is_label_decl(label4) << endl;

	cout << mu0_is_data(data1) << mu0_is_data(data2) /*<< mu0_is_data(data3)*/<< mu0_is_data(data4) << endl;
}

#include "mu0.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
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
	

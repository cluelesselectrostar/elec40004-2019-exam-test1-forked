#include "mu0.hpp"

#include <cctype>
#include <cassert>

bool mu0_is_label_decl(const string &s)
{
    // need to start with alphabet, cannot be number.
    // followed by alphanumeric numbers or underscore '_'

    if (s.empty()) {
        return false;
    }

    if (!isalpha(s.front())) {
        return false;
    }

    for(int i=1; i<=s.length()-2; i++){
        if(!(isalnum(s[i]) || s[i]=='_')){
            return false;
        }
    }

    if(s.back()==':'){ //could use s.back()
	    return true;
    } else {
   	    return false;
    }
}

bool mu0_is_data(const string &s)
{
    //decimal integer constants, optional sign,
    //followed by zero or more digits.

    //must be in range for 16 bit 2's complement numbers
    //i.e. −32,768 to 32,767

    if (s.empty()) {
        return false;
    }

    if(!(s[0]=='-' || isdigit(s[0]))){
	    return false;
    }

    for(int i=1; i<s.length(); i++){
        if(!isdigit(s[i])){
            return false;
        }
    }

    int data_string;
    if (s.front() == '-') {
        string mod = s;
        mod.erase(0,1);
        data_string = stoi(mod);
        if (data_string > 32768) {
            return false;
        }
    } else {
        data_string = stoi(s);
        if (data_string > 32767) {
            return false;
        }
    }

    return true;
}

// TODO: overload for mu0_is_instruction which takes a string

bool mu0_is_instruction(const string &s)
{
    // whether the string is LDA, STA, ADD, SUB, JMP, JGE, JNE, 
    // STP, INP or OUT
	assert(!s.empty());
	return (s=="LDA" || s=="STA" || s=="ADD" || s=="SUB" || s=="JMP" || s=="JGE" || s=="JNE" || s=="STP" || s=="INP" || s=="OUT");
}

bool mu0_instruction_has_operand(const string &s)
{
    assert(mu0_is_instruction(s));
    return !( s=="STP" || s=="INP"||s=="OUT" );
}

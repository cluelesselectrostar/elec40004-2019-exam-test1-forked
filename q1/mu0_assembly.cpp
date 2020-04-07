#include "mu0.hpp"

#include <cctype>
#include <cassert>

bool mu0_is_label_decl(const string &s)
{
    assert(!s.empty());
    for(int i=0; i<=s.length()-2; i++){
	if(!(isalnum(s[i]) || s[i]=='_')){
		return false;
	}
    }

    if(s[s.length()-1]==':'){
	return true;
    }else{
   	return false;
    }
}

bool mu0_is_data(const string &s)
{
    assert(!s.empty());
    if(!(s[0]=='-' || isdigit(s[0]))){
	return false;
    }

    for(int i=1; i<s.length(); i++){
	if(!isdigit(s[i])){
		return false;
	}
    }
   
    return true;
}

// TODO: overload for mu0_is_instruction which takes a string

bool mu0_is_instruction(const string &s)
{
	assert(!s.empty());
	return (s=="LDA" || s=="STA" || s=="ADD" || s=="SUB" || s=="JMP" || s=="JGE" || s=="JNE" || s=="STP" || s=="INP" || s=="OUT");
}

bool mu0_instruction_has_operand(const string &s)
{
    assert(mu0_is_instruction(s));
    return !( s=="STP" || s=="INP"||s=="OUT" );
}

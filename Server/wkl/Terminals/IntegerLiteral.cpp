#include "IntegerLiteral.h"
#include <assert.h>

IntegerLiteral::IntegerLiteral(unsigned long long int value, bool negative, SourcePosition pos) : Terminal(TOKEN_int, pos){
	this->_value = value;
	this->_negative = negative;
}

IntegerLiteral* IntegerFromDecimalString(char* value, int len, SourcePosition pos){
	//We can't have length less than 1
	assert(len > 0);
	//Read the sign value
	bool negative = false;
	if(value[0] == '-'){
		negative = true;
		value++;
		len--;
	}
	//Set value to 0 and add stuff
	unsigned long long int data = 0;
	for(int i = 0; i < len; i++){
		data *= 10;
		data += value[i] - '0';
	}
	return new IntegerLiteral(data, negative, pos);
}

#include "SourcePosition.h"

ostream& operator<<(ostream &stream, const SourcePosition &position){
	stream<<"Line "<<position.line()<<":"<<position.col();
	return stream;
}


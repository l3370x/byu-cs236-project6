#include "parameter.h"


Parameter::Parameter(TokenHolder &t, Domain &d) {
    Token nextT = t.getNextToken();
    if (nextT.getType() != ID && nextT.getType() != STRING) {
        throw nextT;
    }
    myParam = nextT;
    if (myParam.type == STRING) {
        d.add(this->myParam.value);
    }
}

string Parameter::toString() {
    string toReturn;
    if (myParam.getType() == STRING) {
        toReturn += "'";
    }
    toReturn += myParam.getValue();
    if (myParam.getType() == STRING) {
        toReturn += "'";
    }
    return toReturn;
}

Parameter::Parameter(Attribute& a) {
	this->myParam.type = STRING;
	if(a.isIDbool){
		this->myParam.type = ID;
	}
	this->myParam.value = a.value;
}

Token Parameter::getMyParam() const {
    return myParam;
}


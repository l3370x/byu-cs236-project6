#include "parameterlist.h"


ParameterList::ParameterList(TokenHolder &t, Domain &d) {
    Parameter nextP(t, d);
    myParameters.push_back(nextP);
    Token nextT = t.peekNextToken();
    while (nextT.getType() == COMMA) {
        nextT = t.getNextToken();
        Parameter nextP2(t, d);
        myParameters.push_back(nextP2);
        nextT = t.peekNextToken();
    }
}

ParameterList::ParameterList() {
}

string ParameterList::toString() {
    string toReturn;
    vector<Parameter>::iterator it;
    for ( it = myParameters.begin() ; it < myParameters.end(); it++ ) {
        Parameter nextP =  *it;
        toReturn += nextP.toString();
        toReturn += ",";
    }
    // remove last extra comma
    toReturn = toReturn.substr(0, toReturn.length() - 1);
    return toReturn;
}


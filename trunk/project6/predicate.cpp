#include "predicate.h"

Predicate::Predicate(TokenHolder &t, Domain &d) {
    Token nextT = t.getNextToken();
    if (nextT.getType() != ID) {
        throw nextT;
    }
    myID = nextT;
    nextT = t.getNextToken();
    if (nextT.getType() != LEFT_PAREN) {
        throw nextT;
    }
    ParameterList nextPL(t, d);
    myParameterList = nextPL;
    nextT = t.getNextToken();
    if (nextT.getType() != RIGHT_PAREN) {
        throw nextT;
    }
}

Predicate::Predicate() {
}

string Predicate::toString() {
    string toReturn;
    toReturn += myID.getValue();
    toReturn += "(";
    toReturn += myParameterList.toString();
    toReturn += ")";
    return toReturn;
}

Token Predicate::getMyId() const {
    return myID;
}

ParameterList Predicate::getMyParameterList() const {
    return myParameterList;
}


#include "factlist.h"

FactList::FactList(TokenHolder &t, Domain &d) {
    Token nextT = t.getNextToken();
    if (nextT.getType() != FACTS) {
        throw nextT;
    }
    nextT = t.getNextToken();
    if (nextT.getType() != COLON) {
        throw nextT;
    }
    nextT = t.peekNextToken();
    while (nextT.getType() != RULES) {
        Fact nextFact(t, d);
        myFacts.push_back(nextFact);
        nextT = t.peekNextToken();
    }
}

FactList::FactList() {
}

string FactList::toString() {
    string toReturn;
    toReturn += "Facts(";
    toReturn += UsefulFunctions::convertInt(myFacts.size());
    toReturn += "):\n";
    vector<Fact>::iterator it;
    for ( it = myFacts.begin() ; it < myFacts.end(); it++ ) {
        Fact nextF = *it;
        toReturn += nextF.toString();
        toReturn += ".\n";
    }
    return toReturn;
}

vector<Fact> FactList::getMyFacts() const {
    return myFacts;
}


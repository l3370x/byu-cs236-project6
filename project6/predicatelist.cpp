#include "predicatelist.h"

PredicateList::PredicateList(TokenHolder &t, Domain &d) {
    Predicate nextP(t, d);
    myPredicates.push_back(nextP);
    Token nextT = t.peekNextToken();
    while (nextT.getType() == COMMA) {
        nextT = t.getNextToken();
        Predicate nextP2(t, d);
        myPredicates.push_back(nextP2);
        nextT = t.peekNextToken();
    }
}

PredicateList::PredicateList() {
}

string PredicateList::toString() {
    string toReturn;
    vector<Predicate>::iterator it;
    for ( it = myPredicates.begin() ; it < myPredicates.end(); it++ ) {
        Predicate nextP =  *it;
        toReturn += nextP.toString();
        toReturn += ",";
    }
    // remove last extra comma
    toReturn = toReturn.substr(0, toReturn.length() - 1);
    return toReturn;
}

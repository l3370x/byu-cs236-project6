#include "rule.h"

Rule::Rule(TokenHolder &t, Domain &d) {
    Predicate nextP(t, d);
    myPredicate = nextP;
    Token nextT = t.getNextToken();
    if (nextT.getType() != COLON_DASH) {
        throw nextT;
    }
    PredicateList pl(t, d);
    myPredicateList = pl;
    nextT = t.getNextToken();
    if (nextT.getType() != PERIOD) {
        throw nextT;
    }
}

Rule::Rule() {
}

string Rule::toString() {
    string toReturn = "  ";
    toReturn += myPredicate.toString();
    toReturn += " :- ";
    toReturn += myPredicateList.toString();
    toReturn += ".\n";
    return toReturn;
}

#include "fact.h"

Fact::Fact(TokenHolder &t, Domain &d) {
    Predicate nextP(t, d);
    myPredicate = nextP;
    Token nextT = t.getNextToken();
    if (nextT.getType() != PERIOD) {
        throw nextT;
    }
}

Fact::Fact() {
}

string Fact::toString() {
    return "  " + myPredicate.toString();
}

Predicate Fact::getMyPredicate() const {
    return myPredicate;
}


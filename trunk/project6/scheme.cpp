#include "scheme.h"

Scheme::Scheme(TokenHolder &t, Domain &d) {
    Predicate nextPred(t, d);
    myPredicate = nextPred;
}

string Scheme::toString() {
    return "  " + myPredicate.toString();
}

Predicate Scheme::getMyPredicate() const {
    return myPredicate;
}



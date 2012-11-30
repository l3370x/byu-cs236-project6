#ifndef SCHEME_H
#define SCHEME_H

#include "schemelist.h"
#include "predicate.h"

class Scheme {
public:
    Scheme(TokenHolder &t, Domain &d);
    string toString();
    Predicate getMyPredicate() const;

    Predicate myPredicate;
};

#endif // SCHEME_H

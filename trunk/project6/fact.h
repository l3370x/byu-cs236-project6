#ifndef FACT_H
#define FACT_H

#include "factlist.h"
#include "predicate.h"

class Fact {
public:
    Fact(TokenHolder &t, Domain &d);
    Fact();
    string toString();
    Predicate getMyPredicate() const;

    Predicate myPredicate;
};

#endif // FACT_H

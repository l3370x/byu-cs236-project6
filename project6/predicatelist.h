#ifndef PREDICATELIST_H
#define PREDICATELIST_H

#include "tokenholder.h"
#include "predicate.h"
#include <vector>

class PredicateList {
public:
    PredicateList(TokenHolder &t, Domain &d);
    PredicateList();
    string toString();

    vector<Predicate> myPredicates;
};

#endif  // PREDICATELIST_H

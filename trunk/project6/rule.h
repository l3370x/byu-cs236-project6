#ifndef RULE_H
#define RULE_H

#include "rulelist.h"
#include "predicate.h"
#include "predicatelist.h"
#include "domain.h"

class Rule {
public:
    Rule(TokenHolder &t, Domain &d);
    Rule();
    string toString();

private:
public:
    Predicate myPredicate;
    PredicateList myPredicateList;

};

#endif // RULE_H

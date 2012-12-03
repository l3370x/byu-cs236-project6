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

public:
    Predicate myPredicate;
    PredicateList myPredicateList;

    string makeDependancyGraph(RuleList & rl);
};

#endif  // RULE_H

#ifndef RULELIST_H
#define RULELIST_H

#include "tokenholder.h"
#include "token.h"
#include "rule.h"
#include "UsefulFunctions.h"
#include <vector>
#include "domain.h"

class Rule;

class RuleList {
public:
    RuleList(TokenHolder &t, Domain &d);
    RuleList();
    string toString();

    vector<Rule> myRules;
};

#endif // RULELIST_H

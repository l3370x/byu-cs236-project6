#ifndef RULELIST_H
#define RULELIST_H

#include "tokenholder.h"
#include "token.h"
#include "rule.h"
#include "UsefulFunctions.h"
#include <vector>
#include "domain.h"
#include <map>
#include "Node.h"

class Rule;

class RuleList {
public:
    RuleList(TokenHolder &t, Domain &d);
    RuleList();
    string toString();

    vector<Rule> myRules;
    void AddToDG(map<string, Node> & DG);
    void findConnections(Node & toAdd, Rule & r);
};

#endif  // RULELIST_H

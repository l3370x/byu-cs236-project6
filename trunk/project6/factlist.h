#ifndef FACTLIST_H
#define FACTLIST_H

#include "tokenholder.h"
#include "fact.h"
#include "UsefulFunctions.h"
#include <vector>
#include "domain.h"

class Fact;

class FactList {
public:
    FactList(TokenHolder &t, Domain &d);
    FactList();
    string toString();
    vector<Fact> getMyFacts() const;

    vector<Fact> myFacts;
};

#endif  // FACTLIST_H

#ifndef PREDICATE_H
#define PREDICATE_H

#include "tokenholder.h"
#include "parameterlist.h"
#include "domain.h"

class Predicate {
public:
    Predicate(TokenHolder &t, Domain &d);
    Predicate();
    string toString();
    Token getMyId() const;
    ParameterList getMyParameterList() const;

    Token myID;
    ParameterList myParameterList;
};

#endif  // PREDICATE_H

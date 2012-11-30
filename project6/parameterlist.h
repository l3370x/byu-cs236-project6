#ifndef PARAMETERLIST_H
#define PARAMETERLIST_H

#include "tokenholder.h"
#include "parameter.h"
#include <vector>
#include "domain.h"

class ParameterList {
public:
    ParameterList(TokenHolder &t, Domain &d);
    ParameterList();
    string toString();

    vector<Parameter> myParameters;
};

#endif // PARAMETERLIST_H

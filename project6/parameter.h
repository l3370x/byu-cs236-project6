#ifndef PARAMETER_H
#define PARAMETER_H

#include "tokenholder.h"
#include "domain.h"
#include "Attribute.h"

class Parameter {
public:
    Parameter(TokenHolder &t, Domain &d);
    Parameter(Attribute & a);
    string toString();
    Token getMyParam() const;

    Token myParam;
};

#endif // PARAMETER_H

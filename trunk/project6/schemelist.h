#ifndef SCHEMELIST_H
#define SCHEMELIST_H

#include "tokenholder.h"
#include "scheme.h"
#include "UsefulFunctions.h"
#include <vector>
#include "domain.h"

class Scheme;

class SchemeList {
public:
    SchemeList(TokenHolder &t, Domain &d);
    SchemeList();
    string toString();
    vector<Scheme> getMySchemes() const;

    vector <Scheme> mySchemes;
};

#endif  // SCHEMELIST_H

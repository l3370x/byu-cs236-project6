#ifndef QUERYLIST_H
#define QUERYLIST_H

#include "tokenholder.h"
#include "query.h"
#include <vector>
#include "UsefulFunctions.h"
#include "domain.h"

class Query;

class QueryList {
public:
    QueryList(TokenHolder &t, Domain &d);
    QueryList();
    string toString();
    vector<Query> getMyQueries() const;

    vector<Query> myQueries;

};

#endif // QUERYLIST_H

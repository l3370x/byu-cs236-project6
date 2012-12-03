#ifndef QUERYLIST_H
#define QUERYLIST_H

#include "tokenholder.h"
#include "query.h"
#include <vector>
#include "UsefulFunctions.h"
#include "domain.h"
#include "Node.h"
#include <map>


class Query;

class QueryList {
public:
    QueryList(TokenHolder &t, Domain &d);
    QueryList();
    string toString();
    vector<Query> getMyQueries() const;

    vector<Query> myQueries;

    void AddToDG(map<string,Node> & DG,RuleList & rl);
};

#endif // QUERYLIST_H

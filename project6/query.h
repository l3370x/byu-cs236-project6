#ifndef QUERY_H
#define QUERY_H

#include "querylist.h"
#include "predicate.h"
#include "Database.h"
#include <iostream>
#include "rulelist.h"
#include "rule.h"

class Query {
public:
    Query(TokenHolder &t, Domain &d);
    Query(Token &t, ParameterList & p);
    Query();
    string toString();
    int parseQuery(Database & f);
    Relation getQueryFinalRelation() const;
    void setQueryFinalRelation(Relation &queryFinalRelation);
    string printFinalRelationValues();
    string makeDependancyGraph(RuleList & rl);
    string postOrder(map<string,Node> & DG);

    Predicate myPredicate;
    Relation queryFinalRelation;
    bool allIdsMatch(vector<Parameter> & QueryVals, const Tuple &nextT, int i);
    void checkTuples(Relation &nextR);
    void checkParameters(const Tuple &nextT);
    bool isValidQuery(vector<Parameter> &QueryValues, const Tuple &nextT,
    		int i);
    string checkFinalRelationTuples(set<string> & toCheck, const Tuple &nextT);
    void checkFinalRelationParameters(vector<Parameter> &QueryValues, int i,
    		set<string> & alreadyDone, const Tuple &nextT, string & add,
    		bool & hasID);
    string checkFinalRelationDuplicates(set<string> & toCheck, string add,
    		bool containsID, bool & changed);
};

#endif // QUERY_H

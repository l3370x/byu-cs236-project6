#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H

#include "tokenholder.h"
#include "schemelist.h"
#include "factlist.h"
#include "rulelist.h"
#include "querylist.h"
#include "domain.h"
#include <iostream>
#include "Database.h"
#include "Node.h"


using namespace std;

class SchemeList;
class FactList;
class RuleList;
class QueryList;

class DatalogProgram {
public:
    DatalogProgram(TokenHolder t);
    string toString();
    void parseQueries();
    void buildDatabase();
    string getQueries();

    SchemeList sl;
    FactList fl;
    RuleList rl;
    QueryList ql;
    Domain d;
    string queries;
    Database db;
    int ruleIterations;
    map<string, Node> DGraph;

    string buildDependancyGraph();
    string EvaluateQueries();
    set<Tuple> addFirst(Predicate & s);
    void buildDatabaseFromScheme(Scheme &s);
    set<Tuple> addAll(set<Tuple> & tups, string s);
    void addVals(vector<Value> & v , int i, set<Tuple> s);
    vector<Tuple> checkPrevQs(Query & Qs , Query & q);
    void compareAndInsertMatches(Query & q, vector<int> & matches,
    		Tuple & it, Query & querys, vector<Tuple> & toReturn);
    vector<Tuple> comparePred(Query & q, vector<int> & matches, Tuple & it);
    void parseFirstPred(vector<Tuple> & Ts, Query & q);
    void parseOtherPreds(vector<Tuple>& Ts, Query& Qs, Query& q);
    vector<Value> findVals(string s);
    void checkTuples(set<Tuple> & tups, Predicate & p);
    void parseRule(Rule & r, int len);
    bool parseRules();

};

#endif // DATALOGPROGRAM_H

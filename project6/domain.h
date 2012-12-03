#ifndef DOMAIN_H
#define DOMAIN_H

#include <set>
#include <string>
#include "UsefulFunctions.h"

class SchemeList;
class FactList;
class RuleList;
class QueryList;

using namespace std;

class Domain {
public:
    Domain(SchemeList sl, FactList fl, RuleList rl, QueryList ql);
    Domain();
    string toString();
    void add(string s);
private:
    set<string> myDomain;
};

#endif  // DOMAIN_H

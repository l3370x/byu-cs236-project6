#include "querylist.h"

QueryList::QueryList(TokenHolder &t, Domain &d) {
    Token nextT = t.getNextToken();
    if (nextT.getType() != QUERIES) {
        throw nextT;
    }
    nextT = t.getNextToken();
    if (nextT.getType() != COLON) {
        throw nextT;
    }
    Query nextQ(t, d);
    myQueries.push_back(nextQ);
    while (t.hasTokens()) {
        Query nextQuery(t, d);
        myQueries.push_back(nextQuery);
    }
}

QueryList::QueryList() {
}

string QueryList::toString() {
    string toReturn;
    toReturn += "Queries(";
    toReturn += UsefulFunctions::convertInt(myQueries.size());
    toReturn += "):\n";
    vector<Query>::iterator it;
    for ( it = myQueries.begin() ; it < myQueries.end(); it++ ) {
        Query nextQ = *it;
        toReturn += "  " + nextQ.toString();
        toReturn += "?\n";
    }
    return toReturn;
}

vector<Query> QueryList::getMyQueries() const {
    return myQueries;
}

void findConnection(Node & toAdd, Query & q, RuleList & rl) {
	vector<Rule>::iterator it;
	int i = 1;
	for ( it = rl.myRules.begin() ; it != rl.myRules.end() ; ++it) {
		if(q.myPredicate.myID.value.compare((*it).myPredicate.myID.value) == 0) {
			string theRule = "R";
			theRule += UsefulFunctions::convertInt(i);
			toAdd.myChildren.insert(theRule);
		}
		i = i + 1;
	}
}

void QueryList::AddToDG(map<string, Node>& DG,RuleList & rl) {
	vector<Query>::iterator it;
	int i = 1;
	for( it = myQueries.begin() ; it != myQueries.end() ; ++it ) {
		Node toAdd(i,true);
		findConnection(toAdd,(*it),rl);
		DG["Q" + UsefulFunctions::convertInt(i)] = toAdd;
		i = i + 1;
	}
}



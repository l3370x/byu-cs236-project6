#include "rulelist.h"

RuleList::RuleList(TokenHolder &t, Domain &d) {
	Token nextT = t.getNextToken();
	if (nextT.getType() != RULES) {
		throw nextT;
	}
	nextT = t.getNextToken();
	if (nextT.getType() != COLON) {
		throw nextT;
	}
	nextT = t.peekNextToken();
	while (nextT.getType() != QUERIES) {
		Rule nextRule(t, d);
		myRules.push_back(nextRule);
		nextT = t.peekNextToken();
	}
}

RuleList::RuleList() {
}

string RuleList::toString() {
	string toReturn;
	toReturn += "Rules(";
	toReturn += UsefulFunctions::convertInt(myRules.size());
	toReturn += "):\n";
	vector<Rule>::iterator it;
	for ( it = myRules.begin() ; it < myRules.end(); it++ ) {
		Rule nextR = *it;
		toReturn += nextR.toString();
	}
	return toReturn;
}

void RuleList::findConnections(Node & toAdd, Rule & r) {
	vector<Predicate>::iterator it2;
	for ( it2 = r.myPredicateList.myPredicates.begin() ;
			it2 != r.myPredicateList.myPredicates.end() ; ++it2 ) {
		vector<Rule>::iterator it;
		int i = 1;
		for ( it = myRules.begin() ; it != myRules.end() ; ++it) {
			if((*it2).myID.value.compare((*it).myPredicate.myID.value) == 0) {
				string theRule = "R";
				theRule += UsefulFunctions::convertInt(i);
				toAdd.myChildren.insert(theRule);
			}
			i = i + 1;
		}
	}
}

void RuleList::AddToDG(map<string, Node>& DG) {
	vector<Rule>::iterator it;
	int i = 1;
	for( it = myRules.begin() ; it != myRules.end() ; ++it ) {
		Node toAdd(i,false);
		findConnections(toAdd,(*it));
		DG["R" + UsefulFunctions::convertInt(i)] = toAdd;
		i = i + 1;
	}
}

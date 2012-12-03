#include "rule.h"

Rule::Rule(TokenHolder &t, Domain &d) {
	Predicate nextP(t, d);
	myPredicate = nextP;
	Token nextT = t.getNextToken();
	if (nextT.getType() != COLON_DASH) {
		throw nextT;
	}
	PredicateList pl(t, d);
	myPredicateList = pl;
	nextT = t.getNextToken();
	if (nextT.getType() != PERIOD) {
		throw nextT;
	}
}

Rule::Rule() {
}

string Rule::toString() {
	string toReturn = "  ";
	toReturn += myPredicate.toString();
	toReturn += " :- ";
	toReturn += myPredicateList.toString();
	toReturn += ".\n";
	return toReturn;
}

string Rule::makeDependancyGraph(RuleList & rl) {
	string toReturn;
	vector<Rule>::iterator it;
	vector<Predicate>::iterator it2;

	for ( it2=myPredicateList.myPredicates.begin() ;
			it2 != myPredicateList.myPredicates.end() ; ++it2 ) {
		int i = 1;
		for ( it=rl.myRules.begin() ; it != rl.myRules.end() ; ++it ) {
			if((*it2).myID.value.compare((*it).myPredicate.myID.value) == 0) {
				toReturn += "  R" + UsefulFunctions::convertInt(i) + "  ";
			}
			i = i + 1;
		}
	}
	return toReturn;
}

#include "query.h"

Query::Query(TokenHolder &t, Domain &d) {
	Predicate nextP(t, d);
	myPredicate = nextP;
	Token nextT = t.getNextToken();
	if (nextT.getType() != Q_MARK) {
		throw nextT;
	}
}

Query::Query() {
}

string Query::toString() {
	return myPredicate.toString();
}

string Query::makeDependancyGraph(RuleList & rl) {
	string toReturn;
	vector<Rule>::iterator it;
	int i = 1;
	for ( it=rl.myRules.begin() ; it != rl.myRules.end() ; ++it ) {
		if(myPredicate.myID.value.compare((*it).myPredicate.myID.value) == 0) {
			toReturn += "  R" + UsefulFunctions::convertInt(i) + "  ";
		}
		i = i + 1;
	}
	return toReturn;
}


string Query::postOrder(map<string,Node> & DG, int i) {
	string toReturn = "  Postorder Numbers\n";
	set<string>::iterator it;
	int j = 0;
	for ( it = DG["Q"+UsefulFunctions::convertInt(i)].myChildren.begin() ;
			it != DG["Q"+UsefulFunctions::convertInt(i)].myChildren.end() ;
			++it) {
		DG["Q"+UsefulFunctions::convertInt(i)].postorder =
				DG["Q"+UsefulFunctions::convertInt(i)].recurseDG(DG,j);
	}
	toReturn += DG["Q"+UsefulFunctions::convertInt(i)].printPostorder(DG);
	toReturn += "\n";
	return toReturn;
}

string Query::ruleEvaluation(map<string,Node> & DG) {
	string toReturn = "  Rule Evaluation Order\n";
	map<string,Node>::iterator it;
	map<int,string> output;
	for ( it = DG.begin() ; it != DG.end() ; ++it) {
		if((*it).second.visited && !(*it).second.isQuery) {
			string toAdd = "    " + (*it).first + "\n";
			output.insert(pair<int,string>((*it).second.postorder,toAdd));
		}
	}
	map<int,string>::iterator it2;
	for ( it2 = output.begin() ; it2 != output.end() ; ++it2 ) {
		toReturn += (*it2).second;
	}
	return toReturn;
}

string Query::backwardEdges(map<string,Node> & DG) {
	string toReturn = "  Backward Edges\n";
	map<string,Node>::iterator it;
	set<string> output;
	for ( it = DG.begin() ; it != DG.end() ; ++it) {
		if(int i = (*it).second.hasBackwardEdge(DG)) {
			string toAdd = "    " + (*it).first + ": R";
			toAdd += UsefulFunctions::convertInt(i) + "\n";
			output.insert(toAdd);
		}
	}
	set<string>::iterator it2;
	for ( it2 = output.begin() ; it2 != output.end() ; ++it2 ) {
		toReturn += (*it2);
	}
	return toReturn;
}

bool Query::allIdsMatch(vector<Parameter> & QueryVals, const Tuple &nextT,
		int i) {
	string val = nextT.myValues[i].val;
	string param = QueryVals[i].myParam.value;
	bool match = true;
	for ( ; i < (int) nextT.myValues.size() ; ++i) {
		if(QueryVals[i].myParam.type == ID && QueryVals[i].myParam.value.
				compare(param) == 0) {
			if(nextT.myValues[i].val.compare(val) != 0) {
				match = false;
				break;
			}
		}
	}
	return match;
}

inline bool operator<(const Tuple& lhs, const Tuple& rhs) {
	for (int i = 0; i < (int) lhs.myValues.size(); ++i) {
		if (lhs.myValues[i].val.compare(rhs.myValues[i].val) != 0) {
			return lhs.myValues[i].val < rhs.myValues[i].val;
		}
	}
	return 0;
}

inline bool operator==(const Tuple& lhs, const Tuple& rhs) {
	for (int i = 0; i < (int) lhs.myValues.size(); ++i) {
		if (lhs.myValues[i].val.compare(rhs.myValues[i].val) != 0) {
			return false;
		}
	}
	return true;
}

bool Query::isValidQuery(vector<Parameter> &QueryValues, const Tuple &nextT,
		int i) {
	if (QueryValues[i].myParam.type == STRING) {
		if (QueryValues[i].myParam.value.compare(nextT.myValues[i].val) != 0) {
			// the tuple's value didn't match the query's so throw it out.
			return false;
		}
		return true;
	} else {
		if(!allIdsMatch(QueryValues, nextT, i)) {
			return false;
		}
		return true;
	}
}

void Query::checkParameters(const Tuple &nextT) {
	vector<Parameter> * QueryValues = &myPredicate.myParameterList.myParameters;
	bool good = true;
	for (int i = 0; i < (int) QueryValues->size(); ++i) {
		if(!isValidQuery(*QueryValues, nextT, i)) {
			good = false;
			break;
		}
	}
	if(good) {
		this->queryFinalRelation.myTuples.insert(nextT);
	}
}

void Query::checkTuples(Relation &nextR) {
	set<Tuple> * myTuples = &nextR.myTuples;
	set<Tuple>::iterator it2;
	for (it2 = myTuples->begin(); it2 != myTuples->end(); ++it2) {
		checkParameters((*it2));
	}
}

int Query::parseQuery(Database & db) {
	vector<Relation> * dbRs = &db.myRelations;
	vector<Relation>::iterator it;
	// go through each relation in the database
	bool set = false;
	for (it = dbRs->begin(); it < dbRs->end(); ++it) {
		if((*it).name.compare(myPredicate.myID.value) == 0) {
			checkTuples((*it));
			if(!set) {
				this->queryFinalRelation.setName((*it).name);
				this->queryFinalRelation.setSch((*it).Sch);
				set = true;
			}
		}
	}
	return this->queryFinalRelation.myTuples.size();
}

Relation Query::getQueryFinalRelation() const {
	return queryFinalRelation;
}

void Query::setQueryFinalRelation(Relation &queryFinalRelation) {
	this->queryFinalRelation = queryFinalRelation;
}

void Query::checkFinalRelationParameters(vector<Parameter> &QueryValues, int i,
		set<string> & alreadyDone, const Tuple &nextT, string & add,
		bool & hasID) {
	if (QueryValues[i].myParam.type == ID) {
		// the parameter of the query is an identifier
		string check = QueryValues[i].myParam.value;
		if (!UsefulFunctions::stringSetContains(alreadyDone, check)) {
			string toAdd;
			toAdd += check + "='" + nextT.myValues[i].val + "', ";
			add += toAdd;
			alreadyDone.insert(check);
			hasID = true;
		}
	}
}

Query::Query(Token& t, ParameterList& p) {
	this->myPredicate.myID = t;
	this->myPredicate.myParameterList = p;
}

string Query::checkFinalRelationDuplicates(set<string> & toCheck, string add,
		bool containsID, bool & changed) {
	string toReturn;
	if (!UsefulFunctions::stringSetContains(toCheck, add) & containsID) {
		toReturn += add;
		changed = true;
	}
	if (changed) {
		toReturn = toReturn.substr(0, toReturn.length() - 2);
		toCheck.insert(add);
		toReturn += "\n  ";
	}
	return toReturn;
}

string Query::checkFinalRelationTuples(set<string> & toCheck,
		const Tuple &nextT) {
	string toReturn;
	set<string> alreadyDone;
	bool changed = false;
	bool containsID = false;
	vector<Parameter> * QueryValues;
	string add;
	QueryValues = &this->myPredicate.myParameterList.myParameters;
	// go through all query parameters.
	for (int i = 0; i < (int) QueryValues->size(); ++i) {
		checkFinalRelationParameters(*QueryValues, i, alreadyDone, nextT,
				add, containsID);
	}
	toReturn += checkFinalRelationDuplicates(toCheck, add, containsID, changed);
	return toReturn;
}

string Query::printFinalRelationValues() {
	string toReturn = "  ";
	set<string> toCheck;
	set<Tuple>::iterator it2;
	set<Tuple> * myTups = &queryFinalRelation.myTuples;
	// look at all tuples in final relation
	for (it2 = myTups->begin(); it2 != myTups->end(); ++it2) {
		toReturn += checkFinalRelationTuples(toCheck, (*it2));
	}
	toReturn = toReturn.substr(0, toReturn.length() - 2);
	return toReturn;
}





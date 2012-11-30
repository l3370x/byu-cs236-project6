#include "datalogprogram.h"

DatalogProgram::DatalogProgram(TokenHolder t) {
	SchemeList SL(t, d);
	sl = SL;
	FactList FL(t, d);
	fl = FL;
	RuleList RL(t, d);
	rl = RL;
	QueryList QL(t, d);
	ql = QL;
	this->ruleIterations = 1;
}

string DatalogProgram::toString() {
	string toReturn;
	toReturn += queries;
	return toReturn;
}

void DatalogProgram::buildDependancyGraph() {
  for( int i = 1 ; i < ql.myQueries.size() ; i++ ) {
    cout << "  Q" << i << endl;  
  }
  for( int i = 1 ; i < rl.myRules.size() ; i++ ) {
    cout << "  R" << i << endl; 
  }
}

void DatalogProgram::parseQueries() {
	vector<Query> * querys = &ql.myQueries;
	vector<Query>::iterator it;
	for (it = querys->begin(); it < querys->end(); it++) {
		queries += (*it).toString() + "? ";
		if (int num = (*it).parseQuery(db)) {
			queries += "Yes(" + UsefulFunctions::convertInt(num) + ")\n";
			queries += (*it).printFinalRelationValues();
		} else {
			queries += "No\n";
		}
	}
}

inline bool operator<(const Tuple& lhs, const Tuple& rhs) {
	for (int i = 0; i < (int) lhs.myValues.size(); i++) {
		if (lhs.myValues[i].val.compare(rhs.myValues[i].val) != 0) {
			return lhs.myValues[i].val < rhs.myValues[i].val;
		}
	}
	return 0;
}

inline bool operator==(const Tuple& lhs, const Tuple& rhs) {
	for (int i = 0; i < (int) lhs.myValues.size(); i++) {
		if (lhs.myValues[i].val.compare(rhs.myValues[i].val) != 0) {
			return false;
		}
	}
	return true;
}

Tuple makeTupleFromFact(Fact &f) {
	Tuple tup;
	vector<Parameter> * params2 = &f.myPredicate.myParameterList.myParameters;
	vector<Parameter>::iterator it4;
	for (it4 = params2->begin(); it4 < params2->end(); it4++) {
		tup.myValues.push_back(Value((*it4).myParam.value));
	}
	return tup;
}


void DatalogProgram::buildDatabaseFromScheme(Scheme &s) {
	Relation r;
	r.setSch(s.myPredicate.myParameterList);
	r.setName(s.myPredicate.myID.value);

	vector<Fact> * facts = &fl.myFacts;
	vector<Fact>::iterator it3;

	for (it3 = facts->begin(); it3 < facts->end(); it3++) {
		if ((*it3).myPredicate.myID.value.compare(r.name) == 0) {
			r.myTuples.insert(makeTupleFromFact((*it3)));
		}
	}
	this->db.addRelation(r);
}

vector<int> findMatches(Query & querys, Query & q) {
	vector<int> toReturn;
	for ( int i = 0 ;
			i < (int) q.myPredicate.myParameterList.myParameters.size() ; ++i) {
		if( q.myPredicate.myParameterList.myParameters[i].myParam.type == ID) {
			for ( int j = 0 ;
					j < (int) querys.myPredicate.myParameterList.myParameters
							.size();
					++j) {
				if ( querys.myPredicate.myParameterList.
						myParameters[j].myParam.type == ID &&
						q.myPredicate.myParameterList.
						myParameters[i].myParam.value.compare(
								querys.myPredicate.myParameterList.
								myParameters[j].myParam.value) == 0) {
					toReturn.push_back(i);
					toReturn.push_back(j);
					break;
				}
			}
		}
	}
	vector<int>::iterator it;
	return toReturn;
}

void editQuery(Query & q , vector<int> & v, Tuple & t) {

	for ( int i = 0 ; i < (int) v.size() ; i = i + 2) {
		q.myPredicate.myParameterList.myParameters[v[i]].myParam.type = STRING;
		q.myPredicate.myParameterList.myParameters[v[i]].myParam.value =
				t.myValues[(v[i+1])].val;
	}
}

vector<Tuple> DatalogProgram::comparePred(Query & q, vector<int> & matches,
		Tuple & it) {
	editQuery(q, matches, (it));
	q.parseQuery(db);
	vector<Tuple> newTups;
	copy(q.queryFinalRelation.myTuples.begin(),
			q.queryFinalRelation.myTuples.end(), back_inserter(newTups));
	return newTups;
}

void insertMatches(vector<Tuple> & newTups, Query & querys,
		vector<Parameter> & qPs, vector<Tuple> & toReturn, Tuple it) {
	vector<Tuple>::iterator it2;
	for ( it2 = newTups.begin() ; it2 < newTups.end() ; ++it2) {
		Tuple t = (it);
		t.mySchema = Schema(querys.myPredicate.myParameterList.myParameters);
		for ( int i = 0 ; i < (int) (*it2).myValues.size() ; ++i) {
			t.myValues.push_back((*it2).myValues[i]);
			t.mySchema.myAttributes.push_back(Attribute(qPs[i].myParam));
		}
		toReturn.push_back(t);
	}
}

void DatalogProgram::compareAndInsertMatches(Query & q, vector<int> & matches,
		Tuple & it, Query & querys, vector<Tuple> & toReturn) {
	vector<Parameter> qPs = q.myPredicate.myParameterList.myParameters;
	vector<Tuple> newTups = comparePred(q, matches, it);
	insertMatches(newTups, querys, qPs, toReturn, it);
	q.queryFinalRelation.myTuples.clear();
	q.myPredicate.myParameterList.myParameters = qPs;
}


vector<Tuple> DatalogProgram::checkPrevQs(Query & querys , Query & q) {
	vector<Tuple> toReturn;
	vector<Tuple> prevTups;
	copy(querys.queryFinalRelation.myTuples.begin(),
			querys.queryFinalRelation.myTuples.end(), back_inserter(prevTups));

	vector<Tuple>::iterator it;
	vector<int> matches = findMatches(querys,q);
	for ( it = prevTups.begin() ; it < prevTups.end() ; ++it) {
		compareAndInsertMatches(q, matches, (*it), querys, toReturn);
	}
	return toReturn;
}

vector<int> matchValues(Relation & toAdd, vector<Tuple> & tups) {
	vector<int> valsToGet;
	for ( int i = 0 ; i < (int) toAdd.Sch.myAttributes.size() ;	++i) {
		for ( int j = 0 ; j < (int)tups[0].mySchema.myAttributes.size() ; ++j) {
			if( tups[0].mySchema.myAttributes[j].value.
					compare(toAdd.Sch.myAttributes[i].value) == 0) {
				valsToGet.push_back(j);
				break;
			}
		}
	}
	return valsToGet;
}

void selectValues(vector<Tuple> & tups, Relation & toAdd,
		vector<int> & valsToGet) {
	vector<Tuple>::iterator it;
	for ( it = tups.begin() ; it < tups.end() ; ++it) {
		Tuple toInsert;
		toInsert.mySchema = toAdd.Sch;
		for ( int i = 0 ; i < (int) valsToGet.size() ; ++i) {
			toInsert.myValues.push_back((*it).myValues[valsToGet[i]]);
		}
		toAdd.myTuples.insert(toInsert);
	}
}

void findFacts(vector<Tuple> & tups, Relation & toAdd) {
	vector<int> valsToGet = matchValues(toAdd, tups);
	selectValues(tups, toAdd, valsToGet);
}

void DatalogProgram::parseFirstPred(vector<Tuple> & tuples, Query & q) {
	q.parseQuery(db);
	copy(q.queryFinalRelation.myTuples.begin(),
			q.queryFinalRelation.myTuples.end(), back_inserter(tuples));
	for ( int i = 0 ; i < (int) tuples.size() ; i++ ) {
		tuples[i].mySchema.myAttributes.clear();
		for ( int j = 0 ; j < (int) q.myPredicate.myParameterList.
		myParameters.size() ; j++) {
			tuples[i].mySchema.myAttributes.push_back(Attribute(
					q.myPredicate.myParameterList.
					myParameters[j].myParam));
		}
	}
}

void DatalogProgram::parseOtherPreds(vector<Tuple>& tuples, Query& querys,
		Query& q) {
	tuples.clear();
	tuples = checkPrevQs(querys,q);
	if(!tuples.empty()) {
		querys.queryFinalRelation.myTuples.clear();
		copy(tuples.begin(), tuples.end(),
				inserter(querys.queryFinalRelation.myTuples,
						querys.queryFinalRelation.myTuples.end()));
		querys.myPredicate.myParameterList.myParameters.clear();
		for ( int i = 0 ; i < (int) tuples[0].mySchema.myAttributes.size();
				i++ ) {
			querys.myPredicate.myParameterList.myParameters
			.push_back(Parameter(tuples[0].mySchema.myAttributes[i]));
		}
	}
}

void DatalogProgram::parseRule(Rule & r, int len) {
	Relation toAdd(r.myPredicate.myID.value,
			Schema(r.myPredicate.myParameterList.myParameters));
	bool first = true;
	Query querys;
	vector<Tuple> tuples;
	vector<Predicate>::iterator it;
	for(it = r.myPredicateList.myPredicates.begin() ;
			it < r.myPredicateList.myPredicates.end() ; ++it) {
		Query q((*it).myID,(*it).myParameterList);
		if(first){
			parseFirstPred(tuples, q);
			querys = q;
			first = false;
		} else {
			parseOtherPreds(tuples, querys, q);
		}
	}
	if(!tuples.empty()) {
		findFacts(tuples, toAdd);
		db.addFromRule(toAdd);
	}
}

bool DatalogProgram::parseRules() {
	vector<Rule>::iterator it;
	int startingLength = db.size();
	for(it = rl.myRules.begin() ; it < rl.myRules.end() ; ++it) {
		parseRule((*it), startingLength);
	}
	int endingLength = db.size();
	return endingLength > startingLength;
}

void DatalogProgram::buildDatabase() {
	vector<Scheme> * Schemes = &sl.mySchemes;
	vector<Scheme>::iterator it;

	for (it = Schemes->begin(); it < Schemes->end(); ++it) {
		buildDatabaseFromScheme((*it));
	}

	while(parseRules()) {
		ruleIterations = ruleIterations + 1;
	}
	queries += "Schemes populated after ";
	queries += UsefulFunctions::convertInt(ruleIterations);
	queries += " passes through the Rules.\n";

}

string DatalogProgram::getQueries() {
	return queries;
}

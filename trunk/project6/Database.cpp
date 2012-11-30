/*
 * Database.cpp
 *
 *  Created on: Oct 2, 2012
 *      Author: aaron
 */

#include "Database.h"

Database::Database() {
}

Database::~Database() {
}

void Database::addRelation(Relation r) {
	myRelations.push_back(r);
}

vector<Relation> Database::getMyRelations() const {
	return myRelations;
}

string Database::toString() {
	string toReturn;
	vector<Relation>::iterator it;
	for ( it = myRelations.begin() ; it < myRelations.end(); it++ ) {
		Relation nextR =  *it;
		toReturn += nextR.toString();
		toReturn += "\n-------------------------------------\n";
	}
	return toReturn;
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

void Database::addFromRule(Relation& r) {
	if(r.myTuples.size() == 0){
		return;
	}
	bool added = false;
	vector<Relation>::iterator it;
	for ( it = myRelations.begin() ; it < myRelations.end(); it++ ) {
		if((*it).name.compare(r.name) == 0) {
			added = true;
			set<Tuple>::iterator it2;
			for ( it2 = r.myTuples.begin() ; it2 != r.myTuples.end() ; ++it2){
				(*it).myTuples.insert((*it2));
			}
			break;
		}
	}
	if(!added){
		myRelations.push_back(r);
	}
}

int Database::size() {
	int toReturn = 0;
	vector<Relation>::iterator it;
	for ( it = myRelations.begin() ; it < myRelations.end(); it++ ) {
		toReturn += (*it).myTuples.size();
	}
	return toReturn;
}




/*
 * Relation.cpp
 *
 *  Created on: Oct 2, 2012
 *      Author: aaron
 */

#include "Relation.h"

Relation::Relation() {
}

Relation::Relation(string & s, const Schema & sch) {
	this->name = s;
	this->Sch = sch;
}

void Relation::setSch(Schema sch) {
    Sch = sch;
}

void Relation::setSch(ParameterList & p) {
	vector<Parameter>::iterator it;
	for (it = p.myParameters.begin() ; it < p.myParameters.end() ; ++it) {
		this->Sch.myAttributes.push_back(Attribute((*it).myParam));
	}
}

void Relation::setName(string name) {
    this->name = name;
}

void Relation::rename() {
}

void Relation::select() {
}

void Relation::project() {
}

void Relation::fUnion() {
}

void Relation::join() {
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

string Relation::toString() {
    string toReturn;
    toReturn += "\tRELATION NAME:" + name + ":\n";
    toReturn += Sch.toString();
    set<Tuple>::iterator it;
    for (it = myTuples.begin(); it != myTuples.end(); it++) {
        Tuple nextT = *it;
        toReturn += nextT.toString();
    }
    return toReturn;
}

void Relation::addTuple(Tuple &t) {
    myTuples.insert(t);
}

void Relation::removeTuple(Tuple &t) {
    myTuples.erase(t);
}


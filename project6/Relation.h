/*
 * Relation.h
 *
 *  Created on: Oct 2, 2012
 *      Author: aaron
 */

#ifndef RELATION_H_
#define RELATION_H_

#include <string>
#include <set>
#include "Tuple.h"
#include "Schema.h"
#include "TupleSet.h"
#include "parameterlist.h"
#include <vector>

using namespace std;

class Relation {
public:
    string name;
    Schema Sch;
    set<Tuple> myTuples;

public:
    Relation();
    Relation(string & s, const Schema & sch);
    void setName(string name);
    void setSch(Schema sch);
    void setSch(ParameterList & p);
    string toString();
    void addTuple(Tuple &t);
    void removeTuple(Tuple &t);

    void rename();
    void select();
    void project();
    void fUnion();
    void join();
};

#endif /* RELATION_H_ */

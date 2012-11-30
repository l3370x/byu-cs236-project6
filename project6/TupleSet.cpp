/*
 * TupleSet.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#include "TupleSet.h"

TupleSet::TupleSet() {
}

TupleSet::~TupleSet() {
}

set<Tuple> TupleSet::getMyTuples() const {
    return myTuples;
}


void TupleSet::insert(Tuple t) {
    // myTuples.insert(t);
}

string TupleSet::toString() {
    string toReturn;
    set<Tuple>::iterator it;
    for (it = myTuples.begin(); it != myTuples.end(); it++) {
        Tuple t = *it;
        toReturn += t.toString();
    }
    return toReturn;
}


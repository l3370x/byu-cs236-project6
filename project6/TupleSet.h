/*
 * TupleSet.h
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#ifndef TUPLESET_H_
#define TUPLESET_H_

#include <set>
#include <string>
#include "Tuple.h"

using namespace std;

class TupleSet {
public:
    TupleSet();
    virtual ~TupleSet();
    set<Tuple> getMyTuples() const;
    void insert(Tuple t);
    string toString();

private:
    set<Tuple> myTuples;
};

#endif /* TUPLESET_H_ */

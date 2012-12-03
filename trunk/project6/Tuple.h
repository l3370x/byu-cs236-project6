/*
 * Tuple.h
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#ifndef TUPLE_H_
#define TUPLE_H_

#include <map>
#include "Attribute.h"
#include "Value.h"
#include <vector>
#include "Schema.h"

using namespace std;



class Tuple {
public:
    Tuple();
    string toString();

    mutable Schema mySchema;
    vector<Value> myValues;
};

#endif  /* TUPLE_H_ */

/*
 * Tuple.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#include "Tuple.h"

Tuple::Tuple() {
}


string Tuple::toString() {
    string toReturn;
    vector<Value>::iterator it;
    for (it = myValues.begin(); it < myValues.end(); it++) {
        Value nextV = *it;
        toReturn += nextV.getVal() + ",";
    }
    toReturn = toReturn.substr(0, toReturn.length() - 1);
    toReturn += "\n";
    return toReturn;
}



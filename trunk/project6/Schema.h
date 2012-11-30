/*
 * Schema.h
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#ifndef SCHEMA_H_
#define SCHEMA_H_

#include "Attribute.h"
#include <vector>
#include "predicate.h"

using namespace std;

class Schema {
public:
    Schema();
    Schema(vector<Predicate> & p);
    Schema(vector<Parameter> & p);
    Schema(Predicate & p);
    virtual ~Schema();
    void addAttribute(Attribute a);
    void addAtts(Schema & t);
    string toString();

    vector<Attribute> myAttributes;
};

#endif /* SCHEMA_H_ */

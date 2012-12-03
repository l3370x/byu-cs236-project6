/*
 * Database.h
 *
 *  Created on: Oct 2, 2012
 *      Author: aaron
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include <vector>
#include "Relation.h"
#include <iostream>

using namespace std;

class Database {
public:
    Database();
    virtual ~Database();
    void addRelation(Relation r);
    void addFromRule(Relation & r);
    vector<Relation> getMyRelations() const;
    string toString();
    int size();

    vector<Relation> myRelations;
};

#endif  /* DATABASE_H_ */

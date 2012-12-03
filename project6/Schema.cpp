/*
 * Schema.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#include "Schema.h"

Schema::Schema() {
}

Schema::~Schema() {
}


bool operator<(const Attribute& lhs, const Attribute& rhs) {
    return lhs.value < rhs.value;
}

void Schema::addAttribute(Attribute a) {
    myAttributes.push_back(a);
}

Schema::Schema(vector<Predicate>& p) {
    vector<Predicate>::iterator it;
    for ( it = p.begin() ; it < p.end() ; ++it ) {
        this->myAttributes.push_back(Attribute((*it).myID));
    }
}

Schema::Schema(vector<Parameter>& p) {
    vector<Parameter>::iterator it;
    for ( it = p.begin() ; it < p.end() ; ++it ) {
        this->myAttributes.push_back(Attribute((*it).myParam));
    }
}

Schema::Schema(Predicate& p) {
    vector<Parameter>::iterator it;
    for ( it = p.myParameterList.myParameters.begin() ;
            it < p.myParameterList.myParameters.end() ; ++it ) {
        if ((*it).myParam.type == ID) {
            this->myAttributes.push_back(Attribute((*it).myParam));
        }
    }
}

void Schema::addAtts(Schema& t) {
    vector<Attribute>::iterator it;
    for (it = t.myAttributes.begin() ; it < t.myAttributes.end() ; ++it) {
        this->myAttributes.push_back((*it));
    }
}

string Schema::toString() {
    string toReturn;
    vector<Attribute>::iterator it;
    for (it = myAttributes.begin(); it < myAttributes.end(); it++) {
        Attribute nextA = *it;
        toReturn += nextA.toString();
        toReturn += ",";
    }
    // remove last extra comma
    toReturn = toReturn.substr(0, toReturn.length() - 1);
    toReturn += "\n~~~\n";
    return toReturn;
}


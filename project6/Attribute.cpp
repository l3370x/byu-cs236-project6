/*
 * Attribute.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#include "Attribute.h"

Attribute::Attribute(Token t) {
    this->value = t.getValue();
    this->isIDbool = (t.getType() == ID) ? true : false;
}

Attribute::~Attribute() {
}


void Attribute::setValue(string value) {
    this->value = value;
}

bool Attribute::isID() {
    return this->isIDbool;
}


string Attribute::toString() {
    string toReturn;
    toReturn += value;
    return toReturn;
}


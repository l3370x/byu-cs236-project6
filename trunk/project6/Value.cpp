/*
 * Value.cpp
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#include "Value.h"

Value::Value() {
}

Value::Value(string val) {
	this->val = val;
}


string Value::getVal() const {
    return val;
}

Value::~Value() {
}

void Value::setVal(string val) {
    this->val = val;
}



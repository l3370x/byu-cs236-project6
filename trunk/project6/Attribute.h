/*
 * Attribute.h
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include <string>
#include "token.h"

using namespace std;

class Attribute {
public:
    Attribute(Token t);
    virtual ~Attribute();
    void setValue(string value);
    bool isID();
    string toString();

    string value;
    bool isIDbool;
};

#endif /* ATTRIBUTE_H_ */

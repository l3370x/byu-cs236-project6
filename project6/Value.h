/*
 * Value.h
 *
 *  Created on: Oct 3, 2012
 *      Author: aaron
 */

#ifndef VALUE_H_
#define VALUE_H_

#include <string>

using namespace std;

class Value {
public:
    Value();
    Value(string val);
    ~Value();
    string getVal() const;
    void setVal(string val);

    string val;
};

#endif /* VALUE_H_ */

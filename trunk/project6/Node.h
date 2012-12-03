/*
 * Node.h
 *
 *  Created on: Dec 3, 2012
 *      Author: aaron
 */

#ifndef NODE_H_
#define NODE_H_

#include <set>
#include <string>

using namespace std;

class Node {
public:
	Node();
	Node(int i , bool query);
	virtual ~Node();

	bool isQuery;
	int number;
	set<string> myChildren;
	bool visited;
	int postorder;
};

#endif /* NODE_H_ */

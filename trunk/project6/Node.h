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
#include <map>
#include <iostream>
#include "UsefulFunctions.h"

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

	int recurseDG(map<string,Node> & DG, int & i);
	string printPostorder(map<string,Node> & DG);
	int hasBackwardEdge(map<string,Node> & DG);
};

#endif /* NODE_H_ */

/*
 * Node.cpp
 *
 *  Created on: Dec 3, 2012
 *      Author: aaron
 */

#include "Node.h"

Node::Node() {
	isQuery = false;
	number = 1337;
	visited = false;
	postorder = 1337;
}

Node::Node(int i , bool query) {
	isQuery = query;
	number = i;
	postorder = 1337;
	visited = false;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}


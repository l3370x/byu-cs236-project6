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

int Node::recurseDG(map<string,Node> & DG, int & i) {
	if(visited){
		return postorder;
	}
	visited = true;
	if(!myChildren.empty()) {
		set<string>::iterator it;
		for ( it = myChildren.begin() ; it != myChildren.end() ; ++it) {
			DG[(*it)].postorder = DG[(*it)].recurseDG(DG,i);
		}
	}
	i = i+1;
	return i;
}

int Node::hasBackwardEdge(map<string,Node> & DG) {
	if(visited && !isQuery) {
		if(!myChildren.empty()) {
			set<string>::iterator it;
			for ( it = myChildren.begin() ; it != myChildren.end() ; ++it) {
				if(DG[(*it)].postorder >= postorder){
					return DG[(*it)].number;
				}
			}
		}
	}
	return 0;
}

string Node::printPostorder(map<string,Node> & DG) {
	string toReturn;
	set<string> output;
	map<string,Node>::iterator it;
	for ( it = DG.begin() ; it != DG.end() ; ++it) {
		if((*it).second.visited){
			string toOutput = "    " + (*it).first + ": ";
			toOutput += UsefulFunctions::convertInt((*it).second.postorder) +
					"\n";
			output.insert(toOutput);
		}
	}
	set<string>::iterator it2;
	for ( it2 = output.begin() ; it2 !=output.end() ; ++it2 ) {
		toReturn += (*it2);
	}
	return toReturn;

}

#include "querylist.h"

QueryList::QueryList(TokenHolder &t, Domain &d) {
    Token nextT = t.getNextToken();
    if (nextT.getType() != QUERIES) {
        throw nextT;
    }
    nextT = t.getNextToken();
    if (nextT.getType() != COLON) {
        throw nextT;
    }
    Query nextQ(t, d);
    myQueries.push_back(nextQ);
    while (t.hasTokens()) {
        Query nextQuery(t, d);
        myQueries.push_back(nextQuery);
    }
}

QueryList::QueryList() {
}

string QueryList::toString() {
    string toReturn;
    toReturn += "Queries(";
    toReturn += UsefulFunctions::convertInt(myQueries.size());
    toReturn += "):\n";
    vector<Query>::iterator it;
    for ( it = myQueries.begin() ; it < myQueries.end(); it++ ) {
        Query nextQ = *it;
        toReturn += "  " + nextQ.toString();
        toReturn += "?\n";
    }
    return toReturn;
}

vector<Query> QueryList::getMyQueries() const {
    return myQueries;
}


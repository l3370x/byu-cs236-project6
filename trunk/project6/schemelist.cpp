#include "schemelist.h"

SchemeList::SchemeList(TokenHolder &t, Domain &d) {
    Token nextT = t.getNextToken();
    if (nextT.getType() != SCHEMES) {
        throw nextT;
    }
    nextT = t.getNextToken();
    if (nextT.getType() != COLON) {
        throw nextT;
    }
    Scheme nextS(t, d);
    mySchemes.push_back(nextS);
    nextT = t.peekNextToken();
    while (nextT.getType() != FACTS) {
        Scheme nextScheme(t, d);
        mySchemes.push_back(nextScheme);
        nextT = t.peekNextToken();
    }
}

SchemeList::SchemeList() {
}

string SchemeList::toString() {
    string toReturn;
    toReturn += "Schemes(";
    toReturn += UsefulFunctions::convertInt(mySchemes.size());
    toReturn += "):\n";
    vector<Scheme>::iterator it;
    for ( it = mySchemes.begin() ; it < mySchemes.end(); it++ ) {
        Scheme nextS = *it;
        toReturn += nextS.toString();
        toReturn += "\n";
    }
    return toReturn;
}

vector<Scheme> SchemeList::getMySchemes() const {
    return mySchemes;
}


#include "domain.h"

using namespace std;


Domain::Domain() {
}

string Domain::toString() {
    string toReturn;
    toReturn += "Domain(";
    toReturn += UsefulFunctions::convertInt(myDomain.size());
    toReturn += "):\n";
    set<string>::iterator it;
    for (it = myDomain.begin(); it != myDomain.end(); it++) {
        string nextS = *it;
        toReturn += "  '"  + nextS;
        toReturn += "'\n";
    }
    return toReturn;
}

void Domain::add(string s) {
    myDomain.insert(s);
}

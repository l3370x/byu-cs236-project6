#include "tokenholder.h"

TokenHolder::TokenHolder() {
}

void TokenHolder::add(Token t) {
    allTokens.push(t);
    lastToken = t;
}

queue<Token> TokenHolder::getAll() {
    return queue<Token> (allTokens);
}

string TokenHolder::printAll() {
    queue<Token> myCopy(allTokens);
    string toReturn = "";
    int count = 0;
    while  (myCopy.size() != 0) {
        Token t = myCopy.front();
        toReturn += t.toString();
        myCopy.pop();
        count++;
    }
    toReturn += "Total Tokens = " + UsefulFunctions::convertInt(count);
    return toReturn;
}

Token TokenHolder::getNextToken() {
    Token t;
    if (hasTokens()) {
        t = allTokens.front();
        allTokens.pop();
    } else {
        t.setLine(lastToken.getLine());
        t.setType(EOFz);
        t.setValue("EOF");
        throw t;
    }
    return t;
}

int TokenHolder::hasTokens() {
    return allTokens.size();
}

Token TokenHolder::peekNextToken() {
    Token t;
    if (hasTokens()) {
        t = allTokens.front();
        return t;
    } else {
        t.setLine(lastToken.getLine());
        t.setType(EOFz);
        t.setValue("EOF");
        throw t;
    }
}

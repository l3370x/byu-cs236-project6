#ifndef TOKENHOLDER_H
#define TOKENHOLDER_H

#include <queue>
#include "token.h"
#include <string>

using namespace std;

class TokenHolder {
    queue<Token> allTokens;
    Token lastToken;

public:
    TokenHolder();
    void add(Token t);
    queue<Token> getAll();
    string printAll();
    Token getNextToken();
    Token peekNextToken();
    int hasTokens();
};

#endif // TOKENHOLDER_H

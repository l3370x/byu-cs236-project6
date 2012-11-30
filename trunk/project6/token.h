#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "UsefulFunctions.h"

using namespace std;

enum TokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN,
                COLON, COLON_DASH, SCHEMES, FACTS, RULES,
                QUERIES, ID, STRING, COMMENT, WHITESPACE, EOFz
               };


class Token {
public:
    string value;
    int line;
    TokenType type;


public:
    Token();
    ~Token();
    string toString();
    TokenType getType();
    int getLine();
    string getValue();
    void setType(TokenType t);
    void setLine(int l);
    void setValue(string s);
};

#endif // TOKEN_H

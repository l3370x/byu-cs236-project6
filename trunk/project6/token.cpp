#include "token.h"

Token::Token() {
}

Token::~Token() {
}

string Token::toString() {
    string toReturn = "";
    toReturn += "(";
    switch (type) {
    case COMMA:
        toReturn += "COMMA";
        break;
    case PERIOD:
        toReturn += "PERIOD";
        break;
    case Q_MARK:
        toReturn += "Q_MARK";
        break;
    case LEFT_PAREN:
        toReturn += "LEFT_PAREN";
        break;
    case RIGHT_PAREN:
        toReturn += "RIGHT_PAREN";
        break;
    case COLON:
        toReturn += "COLON";
        break;
    case COLON_DASH:
        toReturn += "COLON_DASH";
        break;
    case SCHEMES:
        toReturn += "SCHEMES";
        break;
    case FACTS:
        toReturn += "FACTS";
        break;
    case RULES:
        toReturn += "RULES";
        break;
    case QUERIES:
        toReturn += "QUERIES";
        break;
    case ID:
        toReturn += "ID";
        break;
    case STRING:
        toReturn += "STRING";
        break;
    case EOFz:
        toReturn += "EOF";
        break;
    default:
        toReturn += "ERROR";
        break;
    }
    toReturn += ",\"";
    toReturn += value;
    toReturn += "\",";
    toReturn += UsefulFunctions::convertInt(line);
    toReturn += ")\n";
    return toReturn;
}

TokenType Token::getType() {
    return type;
}
int Token::getLine() {
    return line;
}
string Token::getValue() {
    return value;
}
void Token::setType(TokenType t) {
    type = t;
}
void Token::setLine(int l) {
    line = l;
}
void Token::setValue(string s) {
    value = s;
}

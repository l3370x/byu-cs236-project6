#include "scanner.h"


using namespace std;

scanner::scanner(char *input) {
    wasGoodRead = true;
    s.setUpInput(input);
}


void scanner::badRead(string where) {
    wasGoodRead = false;
    error = "Error on line " + where;
    throw error;
}

bool scanner::checkGoodRead() {
    return wasGoodRead;
}

TokenHolder scanner::getTokenHolder() {
    return tokHolder;
}

string scanner::getError() {
    return error;
}

void scanner::readID() {
    string value = "";
    while (isalnum(currentChar)) {
        value += currentChar;
        currentChar = s.getChar();
    }
    currentToken.setLine(s.getLine());
    currentToken.setType(ID);
    currentToken.setValue(value);
}

void scanner::readString() {
    string value = "";
    currentToken.setLine(s.getLine());
    currentToken.setType(STRING);
    currentChar = s.getChar();  // advance to the next character past initial '
    if (currentChar != 39) {
        while (currentChar != 39) {
            if (s.eofReached) {
                badRead(UsefulFunctions::convertInt(currentToken.getLine()));
                break;
            } else if (currentChar == 10) {
                badRead(UsefulFunctions::convertInt(currentToken.getLine()));
                break;
            }
            value += currentChar;
            currentChar = s.getChar();
        }
    }
    if (!s.eofReached)
        currentChar = s.getChar();  // advance past final '
    currentToken.setValue(value);
}

void scanner::readSpecial() {
    currentToken.setLine(s.getLine());
    string value = "";
    switch (currentChar) {
    case 35:
        currentToken.setType(COMMENT);
        while (currentChar != 10) {
            value += currentChar;
            currentChar = s.getChar();
            if (currentChar == -1)
                break;
        }
        currentToken.setValue(value);
        break;
    case 40:    // (
        currentToken.setType(LEFT_PAREN);
        currentToken.setValue("(");
        break;
    case 41:    // )
        currentToken.setType(RIGHT_PAREN);
        currentToken.setValue(")");
        break;
    case 44:    // ,
        currentToken.setType(COMMA);
        currentToken.setValue(",");
        break;
    case 46:    // .
        currentToken.setType(PERIOD);
        currentToken.setValue(".");
        break;
    case 58:    // :
        currentToken.setType(COLON);
        currentToken.setValue(":");
        if (s.peek() == 45) {
            currentChar = s.getChar();
            currentToken.setType(COLON_DASH);
            currentToken.setValue(":-");
        }
        break;
    case 63:    // ?
        currentToken.setType(Q_MARK);
        currentToken.setValue("?");
        break;
    case -1:
        currentToken.setType(WHITESPACE);
        currentToken.setValue("-1:");
        break;
    default:
        badRead(UsefulFunctions::convertInt(s.getLine()));
        break;
    }
    if (currentChar != -1)
        currentChar = s.getChar();  // advance stream
}

void scanner::readToken() {
    while (isWhiteSpace(currentChar)) {  // remove leading whitespace
        currentChar = s.getChar();
    }
    if (s.eofReached) {
        return;
    }
    if (isalpha(currentChar)) {
        readID();
    } else if (currentChar == 39) {
        readString();
    } else {
        readSpecial();
    }
}

void scanner::checkForKeywords() {
    if (currentToken.getValue().compare("Schemes") == 0) {
        currentToken.setType(SCHEMES);
    }
    if (currentToken.getValue().compare("Facts") == 0) {
        currentToken.setType(FACTS);
    }
    if (currentToken.getValue().compare("Rules") == 0) {
        currentToken.setType(RULES);
    }
    if (currentToken.getValue().compare("Queries") == 0) {
        currentToken.setType(QUERIES);
    }
}


void scanner::saveToken() {
    if (currentToken.getType() != COMMENT)
        tokHolder.add(currentToken);
}

bool scanner::isWhiteSpace(int c) {
    switch (c) {
    case 32:    // space
    case 9:     // tab
    case 10:    // linefeed
    case 11:    // vertical tab
    case 12:    // form feed
    case 13:    // carriage return
        return true;
    default:
        return false;
    }
}

void scanner::scan() {
    currentChar = s.getChar();
    while (!s.eofReached) {
        currentToken.setType(WHITESPACE);
        readToken();
        if (currentToken.getType() == WHITESPACE) {
            break;
        }
        if (!wasGoodRead) {
            break;
        }
        if (currentToken.getType() == ID)
            checkForKeywords();
        saveToken();
    }
}

scanner::~scanner() {
}

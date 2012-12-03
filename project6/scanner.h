#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"
#include "stream.h"
#include "tokenholder.h"
#include <vector>
#include <string>
#include <ctype.h>

using namespace std;

class scanner {
private:  // make private
    myStream s;
    TokenHolder tokHolder;
    string error;
    bool wasGoodRead;
    Token currentToken;
    int currentChar;

public:
    scanner(char * input);
    void scan();
    void saveToken();
    bool isWhiteSpace(int c);
    void readToken();
    void checkForKeywords();
    void readID();
    void readString();
    void readSpecial();
    void badRead(string where);
    bool checkGoodRead();
    TokenHolder getTokenHolder();
    string getError();
    ~scanner();
    /*
      skip whitespace (seperate function)
      maybe skip comments
      switch(stream getChar())
        comma
        .
        .
        .
        colon
        quote - do(read a string) - (should see end quote before endline) - (no string within a string)
        alpha(letter) - do(read an identifier) - (peek function with get function) or (have stream store last char)
            check if identifier matches a Keyword
    */
};

#endif  // SCANNER_H

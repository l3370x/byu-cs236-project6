#ifndef STREAM_H
#define STREAM_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

class myStream {
private: //make private
    int lineNum;
    int currentChar;
    int prevChar;
    ifstream inputStream;
public:
    myStream();
    int getChar();
    int getPreviousChar();
    int getLine();
    int setUpInput(char * input);
    int peek();
    bool eofReached;
};

#endif // STREAM_H

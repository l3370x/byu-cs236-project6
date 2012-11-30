#include "stream.h"


using namespace std;

myStream::myStream() {
    eofReached = false;
    lineNum = 1;
    currentChar = 1337;
}


int myStream::getChar() {
    prevChar = currentChar;
    currentChar = inputStream.get();
    if (currentChar == -1) {
        eofReached = true;
    }
    if (prevChar == 10) {
        lineNum++;
    }
    return currentChar;
}

int myStream::getPreviousChar() {
    return prevChar;
}

int myStream::getLine() {
    return lineNum;
}

int myStream::setUpInput(char *input) {
    inputStream.open(input, ios::in);
    if (inputStream.good()) {
        return 1;
    } else {
        return -1;
    }
}

int myStream::peek() {
    return inputStream.peek();
}



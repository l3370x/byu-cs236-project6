#ifndef SAVER_H
#define SAVER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Saver {
    ofstream out;
public:
    Saver(char * filename);
    void save(string what, int error);
    ~Saver();

};

#endif // SAVER_H

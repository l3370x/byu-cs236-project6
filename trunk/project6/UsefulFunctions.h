#ifndef USEFULFUNCTIONS_H
#define USEFULFUNCTIONS_H

#include <string>
#include <sstream>
#include <set>
#include <time.h>


using namespace std;

class UsefulFunctions {
public:
    static string convertInt(int number) {
        stringstream ss;
        ss << number;
        return ss.str();
    }

    static bool stringSetContains(set<string> & mySet, string & s) {
        set<string>::iterator it = mySet.find(s);
        if (it == mySet.end()) {
            return false;
        }
        return true;
    }
    static time_t theTimeIs() {
        time_t seconds;
        seconds = time(NULL);
        return seconds;
    }
};


#endif  // USEFULFUNCTIONS_H

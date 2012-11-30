#include "saver.h"

using namespace std;

Saver::Saver(char *filename) {
    out.open(filename);
}

void Saver::save(string what, int error) {
    if (error) {
        out << "Failure!\n  ";
    } else {
    }
    out << what;
}

Saver::~Saver() {
    out.close();
}

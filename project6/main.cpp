#include <stdlib.h>
#include "token.h"
#include "scanner.h"
#include "saver.h"
#include "datalogprogram.h"
#include <time.h>

using namespace std;

int main(int argc, char **argv) {
    // check command line arguments
    if (argc != 3) {
        cout << "USAGE: lab6 [input filename] [output filename]." << endl;
        return(-1);
    }
    try {
        scanner scn(argv[1]);
        scn.scan();

        DatalogProgram d(scn.getTokenHolder());

        d.buildDatabase();

        // d.parseQueries();
        // d.queries += "Done!";

        string toSave = d.buildDependancyGraph();
        toSave += d.EvaluateQueries();

        Saver sav(argv[2]);
        sav.save(toSave, 0);
    } catch(Token &e) {
        Saver sav(argv[2]);
        sav.save(e.toString(), 1);
        return -1;

    } catch(string &e) {
        Saver sav(argv[2]);
        sav.save(e, 1);
    }

    return 0;
}

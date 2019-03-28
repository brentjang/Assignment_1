#include "DNA.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    DNA dna;
    if(argc == 2)
    {
        if(dna.setFile(argv[1]))
        {
            dna.lengthCalc();
            dna.countOne();
            dna.countPair();
            dna.printSummary();
            dna.appendLines();
            cout << "Finished Processing" << endl;
        }
        else
        {
            cout << "File doesn't exist" << endl;
        }
        dna.clearAll();
    }
    else
    {
        cout << "Invalid Command Line Arguements." << endl;
    }
    return 0;
}

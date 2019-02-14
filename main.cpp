#include "DNA.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    DNA dna;
    bool flag = true;
    while(flag)
    {
        if(dna.setFile())
        {
            dna.lengthCalc();
            dna.countOne();
            dna.countPair();
            dna.printSummary();
            dna.appendLines();
            cout << "Finished Processing" << endl;
        }
        else if(dna.getFileName() == "quit")
        {
            flag = false;
        }
        else
        {
            cout << "File doesn't exist" << endl;
        }
        dna.clearAll();
    }
    return 0;
}

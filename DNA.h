#include <iostream>

using namespace std;

class DNA
{
private:
    int countA;
    int countT;
    int countG;
    int countC;
    int countAA;
    int countAT;
    int countAC;
    int countAG;
    int countCA;
    int countCT;
    int countCC;
    int countCG;
    int countGA;
    int countGT;
    int countGC;
    int countGG;
    int countTA;
    int countTT;
    int countTC;
    int countTG;
    int lines;
    int pairCount;
    int sum;
    double mean;
    double variance;
    double std;
    string fileName;
    double probA;
    double probT;
    double probG;
    double probC;

public:
  DNA();
  ~DNA();
  bool setFile(string name);
  string getFileName();
  void lengthCalc();
  double sumLength();
  double countLines();
  double meanLength();
  double varianceLength();
  double stdLength();
  void countOne();
  void countPair();
  void printSummary();
  void clearAll();
  void appendLines();
};

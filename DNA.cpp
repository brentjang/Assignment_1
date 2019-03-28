#include "DNA.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

DNA::DNA()
{

}
DNA::~DNA()
{
	cout << "deleted" << endl;
}

//takes user input and checks if the input corresponds to a real file
bool DNA::setFile(string name)
{
    ifstream file(name);
    if(file.good())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//return file name
string DNA::getFileName()
{
    return fileName;
}

//clears all variables for multiple files
void DNA::clearAll()
{
    countA = 0;
    countT = 0;
    countG = 0;
    countC = 0;
    countAA = 0;
    countAT = 0;
    countAC = 0;
    countAG = 0;
    countCA = 0;
    countCT = 0;
    countCC = 0;
    countCG = 0;
    countGA = 0;
    countGT = 0;
    countGC = 0;
    countGG = 0;
    countTA = 0;
    countTT = 0;
    countTC = 0;
    countTG = 0;
    lines = 0;
    pairCount = 0;
    mean = 0;
    sum = 0;
    variance = 0;
    std = 0;
    fileName = "";
}

//calculates the number of lines in the file
void DNA::lengthCalc()
{
    ifstream file;
    file.open(fileName);
    string line;
    while(getline(file, line))
    {
        if(line.size() > 0)
        {
            lines++;
        }
    }
    file.close();
}

//return the number of lines
double DNA::countLines()
{
    return double(lines);
}

//returns the sum of characters in lines
double DNA::sumLength()
{
    return double(sum);
}

//calculates and returns the mean length of lines
double DNA::meanLength()
{
    mean = double(sum)/double(lines);
    return mean;
}

//calculates and returns the variance for length of lines
double DNA::varianceLength()
{
    int topSum = 0;
    ifstream file;
    file.open(fileName);
    string line;
    while(getline(file, line))
    {
        topSum += pow(mean - line.size(), 2);
    }
    variance = double(topSum)/double(lines);
    file.close();
    return variance;
}

//calculates and returns the standard deviation for length of lines
double DNA::stdLength()
{
    std = sqrt(variance);
    return std;
}

//counts each valid nucleotide and stores the counts
void DNA::countOne()
{
    ifstream file;
    file.open(fileName);
    string line;
    while(getline(file, line))
    {
        int tempSum = 0;
        int tempCountA = 0;
        int tempCountT = 0;
        int tempCountC = 0;
        int tempCountG = 0;
        for (char c : line)
        {
            c = tolower(c);
            if (c == 'a')
            {
                tempSum++;
                tempCountA++;
            }
            else if (c == 'c')
            {
                tempSum++;
                tempCountC++;
            }
            else if (c == 't')
            {
                tempSum++;
                tempCountT++;
            }
            else if (c == 'g')
            {
                tempSum++;
                tempCountG++;
            }
        }
        //checks for invalid characters/empty lines and throws out line
        if (tempSum != line.size() && line.size() > 0)
        {
            lines--;
            tempSum = 0;
            tempCountA = 0;
            tempCountT = 0;
            tempCountC = 0;
            tempCountG = 0;
        }
        sum += tempSum;
        countA += tempCountA;
        countT += tempCountT;
        countG += tempCountG;
        countC += tempCountC;
    }
    probA = (double)countA/sum;
    probT = (double)countT/sum;
    probG = (double)countG/sum;
    probC = (double)countC/sum;
    file.close();
}

//counts each pair of nucleotides and stores the counts
void DNA::countPair()
{
    ifstream file;
    file.open(fileName);
    string line;
    string pair = "";
    while(getline(file, line))
    {
        int tempCount = 0;
        int tempCountAA = 0;
        int tempCountAT = 0;
        int tempCountAC = 0;
        int tempCountAG = 0;
        int tempCountCA = 0;
        int tempCountCT = 0;
        int tempCountCC = 0;
        int tempCountCG = 0;
        int tempCountGA = 0;
        int tempCountGT = 0;
        int tempCountGC = 0;
        int tempCountGG = 0;
        int tempCountTA = 0;
        int tempCountTT = 0;
        int tempCountTC = 0;
        int tempCountTG = 0;
        for(int i = 0; i < line.size(); i += 2)
        {
            pair = line.substr(i,2);
            transform(pair.begin(), pair.end(), pair.begin(), ::tolower);
            if(pair == "aa")
            {
                tempCount++;
                tempCountAA++;
            }
            else if(pair == "at")
            {
                tempCount++;
                tempCountAT++;
            }
            else if(pair == "ac")
            {
                tempCount++;
                tempCountAC++;
            }
            else if(pair == "ag")
            {
                tempCount++;
                tempCountAG++;
            }
            else if(pair == "ca")
            {
                tempCount++;
                tempCountCA++;
            }
            else if(pair == "ct")
            {
                tempCount++;
                tempCountCT++;
            }
            else if(pair == "cc")
            {
                tempCount++;
                tempCountCC++;
            }
            else if(pair == "cg")
            {
                tempCount++;
                tempCountCG++;
            }
            else if(pair == "ga")
            {
                tempCount++;
                tempCountGA++;
            }
            else if(pair == "gt")
            {
                tempCount++;
                tempCountGT++;
            }
            else if(pair == "gg")
            {
                tempCount++;
                tempCountGG++;
            }
            else if(pair == "gc")
            {
                tempCount++;
                tempCountGC++;
            }
            else if(pair == "ta")
            {
                tempCount++;
                tempCountTA++;
            }
            else if(pair == "tt")
            {
                tempCount++;
                tempCountTT++;
            }
            else if(pair == "tg")
            {
                tempCount++;
                tempCountTG++;
            }
            else if(pair == "tc")
            {
                tempCount++;
                tempCountTC++;
            }
        }
        //checks for invlid pairs/empty lines and throws out the line
        if(line.size()%2 == 0 && line.size() > 0)
        {
            //for even length lines
            if(line.size()/2 == tempCount)
            {
                pairCount += tempCount;
                countAA += tempCountAA;
                countAT += tempCountAT;
                countAC += tempCountAC;
                countAG += tempCountAG;
                countCA += tempCountCA;
                countCT += tempCountCT;
                countCC += tempCountCC;
                countCG += tempCountCG;
                countGA += tempCountGA;
                countGT += tempCountGT;
                countGC += tempCountGC;
                countGG += tempCountGG;
                countTA += tempCountTA;
                countTT += tempCountTT;
                countTC += tempCountTC;
                countTG += tempCountTG;
            }
        }
        else if(line.size()%2 == 1)
        {
            //for odd length lines
            if((line.size()-1)/2 == tempCount)
            {
                pairCount += tempCount;
                countAA += tempCountAA;
                countAT += tempCountAT;
                countAC += tempCountAC;
                countAG += tempCountAG;
                countCA += tempCountCA;
                countCT += tempCountCT;
                countCC += tempCountCC;
                countCG += tempCountCG;
                countGA += tempCountGA;
                countGT += tempCountGT;
                countGC += tempCountGC;
                countGG += tempCountGG;
                countTA += tempCountTA;
                countTT += tempCountTT;
                countTC += tempCountTC;
                countTG += tempCountTG;
            }
        }
    }
    file.close();
}

//writes the summary of given text file to "brentjang.out.txt"
void DNA::printSummary()
{
    string outName = "brentjang.out.txt";
    ofstream printFile(outName);
    printFile << "Brent Jang\nStudent ID: 2270115\nAssignment 1\n" << endl;
    printFile << "The sum of the DNA lengths: " << sumLength() << endl;
    printFile << "The number of DNA stands: " << countLines() << endl;
    printFile << "The mean length of DNA stands: " << meanLength() << endl;
    printFile << "The variance of lengths in DNA stands: " << varianceLength() << endl;
    printFile << "The standard deviation of length in DNA stands: " << stdLength() << endl;
    printFile << '\n';
    printFile << "The probability of A's is: " << 100*double(countA)/sumLength() << endl;
    printFile << "The probability of T's is: " << 100*double(countT)/sumLength() << endl;
    printFile << "The probability of G's is: " << 100*double(countG)/sumLength() << endl;
    printFile << "The probability of C's is: " << 100*double(countC)/sumLength() << endl;
    printFile << '\n';
    printFile << "The probability of AA's is: " << 100*double(countAA)/pairCount << endl;
    printFile << "The probability of AT's is: " << 100*double(countAT)/pairCount << endl;
    printFile << "The probability of AG's is: " << 100*double(countAG)/pairCount << endl;
    printFile << "The probability of AC's is: " << 100*double(countAC)/pairCount << endl;
    printFile << "The probability of TA's is: " << 100*double(countTA)/pairCount << endl;
    printFile << "The probability of TT's is: " << 100*double(countTT)/pairCount << endl;
    printFile << "The probability of TG's is: " << 100*double(countTG)/pairCount << endl;
    printFile << "The probability of TC's is: " << 100*double(countTC)/pairCount << endl;
    printFile << "The probability of GA's is: " << 100*double(countGA)/pairCount << endl;
    printFile << "The probability of GT's is: " << 100*double(countGT)/pairCount << endl;
    printFile << "The probability of GG's is: " << 100*double(countGG)/pairCount << endl;
    printFile << "The probability of GC's is: " << 100*double(countGC)/pairCount << endl;
    printFile << "The probability of CA's is: " << 100*double(countCA)/pairCount << endl;
    printFile << "The probability of CT's is: " << 100*double(countCT)/pairCount << endl;
    printFile << "The probability of CG's is: " << 100*double(countCG)/pairCount << endl;
    printFile << "The probability of CC's is: " << 100*double(countCC)/pairCount << endl;
    printFile.close();
}

//appends 1000 strands to the text file based on probabilities calculated above
void DNA::appendLines()
{
    string outName = "brentjang.out.txt";
    ofstream printFile(outName, ios_base::app);
    printFile << "\n1000 Stands" << endl;
    for(int i = 0; i < 1000; i++)
    {
        float rand1 = ((float) rand()/RAND_MAX);
        float rand2 = ((float) rand()/RAND_MAX);
        float c = sqrt(-2 * log(rand1)) * cos(2 * M_PI * rand2);
        int strandLength = (std * c) + mean;
        string newStrand = "";
        //checks for >0 strand length
        if(strandLength >= 1)
        {
            for(int j = 0; j < strandLength; j++)
            {
                float nucleoProb = ((float) rand()/RAND_MAX);
                if((probT+probG+probA+probC) > nucleoProb && nucleoProb > (probG+probA+probC))
                {
                    newStrand += "T";
                }
                else if((probG+probA+probC) > nucleoProb && nucleoProb > (probA+probC))
                {
                    newStrand += "G";
                }
                else if((probA+probC) > nucleoProb && nucleoProb > probA)
                {
                    newStrand += "C";
                }
                else if(probA > nucleoProb)
                {
                    newStrand += "A";
                }
            }
            printFile << newStrand << endl;
        }
        else
        {
            i--;
        }
    }
    printFile.close();
}

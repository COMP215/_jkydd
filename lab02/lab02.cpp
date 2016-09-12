#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

int RandomWordGenorator()
{
    ofstream outfile("randomwords.txt");

    srand (time(0));
    int numberofwords, lengthofwords, numberofletters = 0;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string wordline;

    numberofwords = 10;
    lengthofwords = 10;

    string wordarray[numberofwords];

    steady_clock timer;
    auto start = timer.now();


    for (int j = 0; j < numberofwords; j++)
    {
        wordline = "";
        for (int i = 0; i < lengthofwords; i++)
        {
            numberofletters = rand() % 26;
            wordline = wordline + alphabet[numberofletters];
        }
        wordarray[j] = wordline;
    }

    sort(wordarray, wordarray + sizeof wordarray / sizeof wordarray[0]);
    for (int j = 0; j < numberofwords; j++)
    {
        outfile << wordarray[j] << endl;
    }

    outfile.close();

    auto end = timer.now();

    duration<double> elapsedseconds = end-start;
    cout << "elapsed time: " << elapsedseconds.count() << "s\n";
}

int main()
{
RandomWordGenorator();
}


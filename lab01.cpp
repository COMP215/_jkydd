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

int one()
{
    ofstream outfile("randomwords.txt");

    srand (time(0));
    int wordnum, wordlen, letternum = 0;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string word;

    cout << "enter the number of words: ";
    cin >> wordnum;
    cout << "enter the length of words: ";
    cin >> wordlen;

    string words[wordnum];

    steady_clock timer;
    auto start = timer.now();


    for (int j = 0; j < wordnum; j++)
    {
        word = "";
        for (int i = 0; i < wordlen; i++)
        {
            letternum = rand() % 26;
            word = word + alphabet[letternum];
        }

        //cout << word << endl;
        words[j] = word;
    }

    sort(words, words + sizeof words / sizeof words[0]);
    for (int j = 0; j < wordnum; j++)
    {
        outfile << words[j] << endl;
    }

    outfile.close();

    auto end = timer.now();

    duration<double> elapsed_seconds = end-start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

int main()
{
one();
}


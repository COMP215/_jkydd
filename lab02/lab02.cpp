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
    int number_of_words, length_of_words, number_of_letters = 0;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string word_line;
    number_of_words = 10;
    length_of_words = 10;
    string word_array[number_of_words];
    steady_clock timer;
    auto start = timer.now();
    for (int j = 0; j < number_of_words; j++)
    {
        word_line = "";
        for (int i = 0; i < length_of_words; i++)
        {
            number_of_letters = rand() % 26;
            word_line = word_line + alphabet[number_of_letters];
        }
        word_array[j] = word_line;
    }
    sort(word_array, word_array + sizeof word_array / sizeof word_array[0]);
    for (int j = 0; j < number_of_words; j++)
    {
        outfile << word_array[j] << endl;
    }
    outfile.close();
    auto end = timer.now();
    duration<double> elapsed_seconds = end-start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

int main()
{
RandomWordGenorator();
}


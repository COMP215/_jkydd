#include <iostream>
#include <vector>
#include <string>
using namespace std;

void FindSubSequences (string string1,vector <string> subsequences,int vectorindex,bool smallest)
{
    string left = {};
    string right = {};
    if (!smallest){
        int left_size = string1.size()-1;
        for (int i = 0; i < left_size; i++)
        {
            cout << i << endl;
            left.append(string1,i,1);
            right.append(string1,i+1,1);
        }
        cout << "left" << left << endl;
        cout << "right" << right << endl;
        cout << "left size" << left.size() << endl;
        if (left.size() == 1 | right.size() == 1)
        {
            smallest = true;
        }
        subsequences.push_back(left);
        subsequences.push_back(right);
        cout << subsequences[vectorindex] << "   " << subsequences[vectorindex+1] << endl;
        vectorindex = vectorindex + 2;
        FindSubSequences(left, subsequences, vectorindex,smallest);
        FindSubSequences(right, subsequences, vectorindex,smallest);
    }
}
    //split(left,left_size,right,right_size,string1);

int main()
{
    string string1 = "bacbad";
    vector <string> subsequences;
    int vectorindex = 0;
    bool smallest = false;
    FindSubSequences(string1,subsequences,vectorindex,smallest);
}

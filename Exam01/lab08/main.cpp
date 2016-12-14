#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> FindSubSequences (string string1,vector <string> subsequences,int vectorindex,bool smallest)
{
    string left = {};
    string right = {};
    if (!smallest){
        int left_size = string1.size()-1;
        for (int i = 0; i < left_size; i++)
        {
            //cout << i << endl;
            left.append(string1,i,1);
            right.append(string1,i+1,1);
        }
        //cout << "left" << left << endl;
        //cout << "right" << right << endl;
        //cout << "left size" << left.size() << endl;
        if (left.size() == 1 | right.size() == 1)
        {
            smallest = true;
        }
        subsequences.push_back(left);
        subsequences.push_back(right);
        //cout << subsequences[vectorindex] << "   " << subsequences[vectorindex+1] << endl;
        vectorindex = vectorindex + 2;
        subsequences.push_back(FindSubSequences(left, subsequences, vectorindex, smallest));
        FindSubSequences(right, subsequences, vectorindex, smallest);
    }
    return subsequences;
}
    //split(left,left_size,right,right_size,string1);
void searchvector(string searchTerm, vector <string> tosearch)
{

}
int main()
{
    string string1 = "bacbad";
    string string2 = "abcdad";
    vector <string> subsequences1;
    vector <string> subsequences2;
    int vectorindex = 0;
    bool smallest = false;
    subsequences1 = FindSubSequences(string1,subsequences1,vectorindex,smallest);
    FindSubSequences(string2,subsequences2,vectorindex,smallest);
    cout << subsequences1.size() << endl;
}

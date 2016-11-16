#include <iostream>
#include <vector>
#include <array>
using namespace std;

void mergerecursive(vector <int> startlist, int ibegin, int imiddle, int iend)
{
    cout << "values" << ibegin << imiddle << iend;
   //make left and right arrays
   vector <int> L = {};
   vector <int> R = {};
cout << "split";
   //l = left half of start list
   for (int i = 0; i < imiddle; i++)
   {
       cout<< "loop";
       cout<< "startlist " << startlist[i] << "index" << i << endl;
        L[i] = startlist[i];
   }

   //r = right half of start list
    for (int i = 0; i < iend; i++)
   {
        R[i] = startlist[i + imiddle];
   }
}

void mergesort(vector <int> startlist, int n)
{
    int ibegin = 0;
    int iend = n;
    int imiddle = (ibegin + iend) / 2;
    cout<< "firts" << endl;
    mergerecursive(startlist, ibegin, imiddle, iend);
    cout<<"second";
    //mergesort(startlist,n);

}
void bubblesort(int tosort[],int n)
{
    bool switchcount = true;
    while(switchcount){
        switchcount = false;
        for (int i = 0; i < n; i++){
            cout << "loop" << endl;
            cout << tosort[i] << ">" <<  tosort[i+1] << endl;
            if (tosort[i] > tosort[i+1]){
                swap(tosort[i],tosort[i+1]);
                switchcount = true;
                cout << "switch" << endl;
                cout << tosort[i] << "<->" << tosort[i+1] << endl;
            }
        }
    }
}

void PrintArray(int arrays[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arrays[i] << ", ";
    }
    cout << "end" << endl;
}

void SelectionSort(int* array, int array_size)
{
	int min_index;
	for (int i = 0; i < array_size; i++) {
		min_index = i;
		for (int j = i; j < array_size; j++) {
			if (array[min_index] > array[j]) {
				min_index = j;
			}/*if*/
		}/*for*/
		swap(array[i], array[min_index]);
	}/*for*/
	PrintArray(array, array_size);
}/*SelectionSort*/


int main()
{
    int arrayone[8] = {8,2,3,4,1,9,10,7};
    int arraytwo[] = {};
    vector <int> startlist = {8,2,3,4,1,9,10,7};
    //PrintArray(arrayone,8);
    //bubblesort(arrayone,8);
    //PrintArray(arrayone,8);
    mergesort(startlist,8);
}

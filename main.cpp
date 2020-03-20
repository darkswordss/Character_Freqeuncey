#include <iostream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;
void printTheChart (vector<char> myData){
    int counter=0;
    for (int index=0; index<myData.size();index++){
        if (counter==0){
            cout<<myData[index]<<":";
        }
        if(myData[index]==myData[index+1]){
            counter++;
        }
        else{
            cout<<counter+1<<std::endl;
            counter=0;
        }

    }
}
void heapify(vector<char> &arr, int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void heapSort(vector<char> &arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

vector<char> evaluateTheFile(string ss) {
    vector<char> myData;
    ifstream inFile;

    inFile.open("../" + ss );
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    char ch;
    while (inFile.get(ch)) {
        myData.push_back(ch);
    }
    return myData;

}

int main() {


    vector<vector<char> > myData;

    string fileNames[3] = {"iliad_1.txt", "aaa.txt", "alphabet.txt"};
    for (int index = 0; index < 3; index++) {
        myData.push_back(evaluateTheFile(fileNames[index]));
    }
    //sort the data
    for (int index = 0; index < 3; index++) {
        int n = myData[index].size() - 1;
        //heap sort the data
        heapSort(myData[index], n);
        cout<<"\n";
        printTheChart(myData[index]);
    }



    return 0;


}

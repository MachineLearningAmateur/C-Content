//include any standard libraries needed
#include <iostream>
#include <fstream>
using namespace std;
//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize) {
    double total = 0;
    for (int i = 0; i < arraySize; i++) {
        total += array[i];
    }
    return total/arraySize;
}
//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index) {
    for (int i = index; i < arraySize; i++) {
        if(i != arraySize-1)
            array[i] = array[i+1];
    }
    arraySize = arraySize - 1;
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i];
        if (arraySize - 1 != i)
            cout << ", ";
    }
    cout << endl;
}


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
    string fileName;
    if (argc == 2) {
        fileName = argv[1];
    }
    else
        return 1;
    
    ifstream nFile(fileName);
    
    if(!nFile.is_open()) {
        cout << "File is not open." << endl;
        return 1;
    }
    
    double array[ARR_CAP];
   // open file and verify it opened
    
   // Declare an array of doubles of size ARR_CAP.
    
    int arrayCnt = 0;
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
    for(int i = 0; i < ARR_CAP; i++) {
        if (nFile >> array[i])
            arrayCnt++;
    }
    
   // Call the mean function passing it this array and output the 
   // value returned.
    cout << "Mean: " << mean(array, arrayCnt) << endl;
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
    cout << "Enter index of value to be removed (0 to " << arrayCnt - 1 << ") :" << endl;
    int index;
    cin >> index;
    cout << "Before removing value: ";
    display(array, arrayCnt);
   // Call the display function to output the array.

   
   // Call the remove function to remove the value at the index
   // provided by the user.
    remove(array, arrayCnt, index);
    
   // Call the display function again to output the array
   // with the value removed.
    cout << "After removing value: ";
    display(array, arrayCnt);
    cout << "Mean: " << mean(array, arrayCnt) << endl;
   // Call the mean function again to get the new mean

   
	return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
   
    // Assign to inputFile value of 2nd command line argument
    // Assign to outputFile value of 3rd command line argument
    
    string inputFile = argv[1];
    string outputFile = argv[2];
    ifstream fileI;
    ofstream fileO;
    string temp; 
    vector<int> v; 
    int sum = 0;
    int count = 0;
   // Create input stream and open input csv file.
   
    
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   fileI.open(inputFile.c_str());
    
    if(!fileI.is_open()){
        cout << "Error opening " << inputFile << endl;
        return 1;
    }
   // Read in integers from input file to vector.
   
    while (getline(fileI, temp, ',')) {
        v.push_back(atoi(temp.c_str()));
    }
    
    for (unsigned int i = 0; i < v.size(); i++) {
        sum += v.at(i);
        count++; 
    }
    
    fileI.close();
   // Close input stream.
    double avg = sum/count;
    cout << avg << endl; 
    
    for (unsigned int i = 0; i < v.size(); i++) {
       v.at(i) = v.at(i) - avg; 
   }
    
    fileO.open(outputFile.c_str());
    
    if (!fileO.is_open()) {
        cout << "Error opening " << outputFile << endl;
        return 1;
    }
    
    for (unsigned int i = 0; i < v.size(); i++) {
        fileO << v.at(i);
        if (i + 1 != v.size()) {
            fileO << ',';
        }
    }
    
   fileO.close(); 
   
   return 0;
}
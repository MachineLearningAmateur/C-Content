#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum (string file);

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Sum: " << fileSum(filename) << endl; 
   return 0;
}

// Place fileSum implementation here
int fileSum (string file) {
    ifstream fileN;
    int sum = 0;
    int x; 
    fileN.open(file.c_str());
    
    if (!fileN.is_open()) {
        cout << "Error opening " << file << endl;
        exit(1);
    }
    while (fileN >> x) {
            sum = sum + x; 
        }
    fileN.close();
    return sum; 
}
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    string filename;
    ifstream fileN; 
    int x;
    int sum = 0;
    cout << "Enter the name of the input file: ";
    cin >> filename;
    cout << endl;
    fileN.open(filename.c_str());
    
    if (!fileN.is_open()) {
        cout << "Error opening " << filename << endl;
        return 1;
    }
    
    while (fileN >> x) {
        sum = sum + x;
        fileN.clear(); 
    }
    
    cout << "Sum:" << sum << endl; 
   return 0;
}
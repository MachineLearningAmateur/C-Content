#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt (string file, char c);

int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;
   
   cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   
   return 0;
}

// Place charCnt implementation here

int charCnt (string file, char c) {
    ifstream fileN;
    string t;
    int count = 0;
    fileN.open(file.c_str());
    if(!fileN.is_open()){
        cout << "Error opening " << file << endl;
        exit(1);
    }
    
    while (getline(fileN, t)) {
        for (unsigned int i = 0; i < t.size(); i++) {
            if (t.at(i) == c)
                count++;
        }
    }
    return count; 
    
}
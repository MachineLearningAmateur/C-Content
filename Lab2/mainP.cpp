#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std; 

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char *argv[]) {
    string fileName = argv[1]; 
    vector<double> fPath;
    vector<double> coLift;
    double fAngle;
    readData(fileName, fPath, coLift);
    for(unsigned int i = 0; i < fPath.size(); i++) {
            cout << fPath.at(i) << ' ';
    }
    cout << endl;
    if (!isOrdered(fPath)) {
        reorder(fPath, coLift);
    }
    for(unsigned int i = 0; i < fPath.size(); i++) {
            cout << fPath.at(i) << ' ';
    }
    string response = "Yes";
    while (response != "No" && response == "Yes") {
        cout << "Choose a flight path angle: ";
        cin >> fAngle;
        cout << interpolation(fAngle, fPath, coLift); 
        cout << endl;
        cout << endl;
        cout << "Choose another flight path angle? ";
        cin >> response;
        cout << endl;
    }
    return 0;
}

void readData(const string& fileName, vector<double>& fpath, vector<double>& coLift) {
    string line;
    ifstream nFile; 
    nFile.open(fileName.c_str());
    double f; 
    double c;
    if(!nFile.is_open()){
        cout << "Error opening " << fileName << endl; 
        exit(1);
    }
    
    while (getline(nFile, line)) {
        stringstream temp(line);
        temp >> f >> c;
        fpath.push_back(f);
        coLift.push_back(c);
        }
}

double interpolation(double pAngle, const vector<double>&fpath, const vector<double>&coLift) {
    double interpol;
     for (unsigned int i = 0; i < fpath.size(); i++) {
            if (fpath.at(i) == pAngle) {
                return coLift.at(i);
            } else if (fpath.at(i) < pAngle && fpath.at(i+1) > pAngle && i+1 != fpath.size()) {
                interpol = coLift.at(i) + (pAngle - fpath.at(i))/(fpath.at(i+1) - fpath.at(i)) * (coLift.at(i+1) - coLift.at(i));
            }
        }
    return interpol; 
}

bool isOrdered(const vector<double>& fpath) {
    bool isOrder = true;
    for (unsigned int i = 0; i + 1 < fpath.size(); i++) {
        if (fpath.at(i) > fpath.at(i+1)) {
            isOrder = false; 
        }
    }
    return isOrder;
}

void reorder(vector<double>& fpath, vector<double>& coLift) {
    int indexH;
    double swap; 
    double min; 
    for(unsigned int i = 0; i < fpath.size(); i++) {
        min = fpath.at(i);
        indexH = i;
        for(unsigned int j = i; j < fpath.size(); j++) {
            if (fpath.at(j) < min) {
                min = fpath.at(j);
                indexH = j;
            }
        }
        swap = fpath.at(i);
        fpath.at(i) = fpath.at(indexH);
        fpath.at(indexH) = swap; 
        swap = coLift.at(i);
        coLift.at(i) = coLift.at(indexH);
        coLift.at(indexH) = swap; 
    }
}
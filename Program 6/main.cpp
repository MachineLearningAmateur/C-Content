#include <iostream>
#include "SortedSet.h"
#include "IntList.h"

using namespace std;

int main() {
    SortedSet trial = SortedSet();
    trial.push_back(5);
    trial.push_back(5);
    trial.push_back(7);
    trial.add(5);
    trial.add(6);
    cout << trial << endl;
    
    SortedSet time(trial);
    cout << time << endl;
    time.clear();
    time.add(2);
    time.add(5);
    time.add(6);
    cout << time << endl;
    if (time.in(5)) {
        cout << "true" << endl;
    }
    time.clear();
    
    time.push_back(51);
    time.push_back(71);
    time.push_back(52);
    time.push_back(32);
    cout << time << endl;
    trial.add(52);
    trial.add(26);
    trial.add(30);
    trial.add(51);
    trial.add(71);
    SortedSet test = trial & time;
    cout << test << endl;
    
    return 0;
}
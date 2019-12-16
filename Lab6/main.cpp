#include "IntVector.h"
#include <iostream>

using namespace std;

int main() {
    IntVector *newVector = new IntVector(10, 20);
//     if (!newVector->empty())
//         cout << "True" << endl;
    cout << newVector->size() << endl;
    cout << newVector->capacity() << endl;
//     cout << newVector->at(0) << endl;
//     cout << newVector->front() << endl;
//     cout << newVector->back() << endl;
//     newVector->insert(newVector->size()-1, 999);
//     newVector->insert(newVector->size()-1, 22);
//     newVector->erase(9);
//     newVector->erase(newVector->size()-1);
//     newVector->push_back(99);
//     newVector->push_back(77);
//     newVector->erase(newVector->size()-1);
//     newVector->push_back(98);
    newVector->resize(30);
    cout << newVector->size() << endl;
    cout << newVector->capacity() << endl;
    
//     cout << newVector->size() << endl;
//     newVector->at(0) = 60;
//     cout << newVector->at(0) << endl;
//     newVector->clear();
//     cout << newVector->size() << endl;
    

    return 0; 
}
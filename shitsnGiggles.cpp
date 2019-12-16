#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
//     int *jargon = new int(30);
//     int *jargon1 = jargon;
//     int *jargon2 = jargon; 
//     cout << *jargon2 << endl;
//     cout << *jargon1 << endl;
//     delete jargon1;
//      jargon = nullptr;
//      jargon1 = nullptr;
//     jargon2 = nullptr;
    
//      int *array = new int [2];
//      array[0] = 2;
//      array[1] = 3;
//      cout << array[0] << endl;
//     cout << array[1] << endl;
//     cout << *(array + 1) << endl;
//    cout << *(&array[1]) << endl;
//     Student test;
//     Student test1;
//     test1 = test; 
    
void remove (int val) {
    Node* currNode = head;
    bool flag = false;
    while (currNode != nullptr) {
        if (currNode->data == val) {
            Node* temp = currNode->next;
            if (head == currNode) {
                head = temp;
            }
            delete currNode;
            currNode = temp;
            flag = true;
        }
        currNode = currNode->next;
        if (flag) {
            return;
        }
    }
}

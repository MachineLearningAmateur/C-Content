#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */

ostream & operator<<(ostream& os, const IntList& ls) {
    if (ls.head == nullptr)
        return os;
    else if (ls.head != nullptr) {
        os << ls.head->data;
        if (ls.head->next != nullptr)
            os << " ";
    }
        IntList update = ls;
        update.head = ls.head->next;
        return (os << update);
}

   /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in.
      Otherwise returns false.
   */

bool IntList::exists(IntNode* start, int value) const {
    if (start == nullptr)
        return false;
    else if (start->data == value) {
        return true; 
    }
    return exists(start->next, value);
}

   /* Returns true if the integer passed in is contained within the IntList.
      Otherwise returns false.
   */

bool IntList::exists(int value) const {
    return exists(head, value);
}
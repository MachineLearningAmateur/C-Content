#include "IntList.h"
#include <iostream>
#include <utility>
using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    if (cpy.head != nullptr) {
    IntNode* temp = cpy.head;
        while (temp) {
            push_back(temp->data);
            temp = temp->next;
        }
    }   
}
    
IntList& IntList::operator=(const IntList &rhs) {
    if (&rhs != this) {
        clear();
        IntNode* temp = rhs.head;
        while (temp) {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}
    

IntList::~IntList() {
    if (head == nullptr)
        tail = nullptr;
    else {
        while (head) {
            pop_front();
        }
        head = nullptr;
        tail = nullptr;
    }
}

void IntList::push_front(int val) {
    if (head == nullptr) {
        head = new IntNode(val);
        tail = head;
    } else {
        IntNode *temp = new IntNode(val);
        temp->next = head;
        head = temp;
    }
}

void IntList::pop_front() {
    if (head != nullptr) {
        IntNode* temp = head->next;
        delete head;
        head = temp;
    }
    if(head == nullptr)
        tail = nullptr;
}

bool IntList::empty() const {
    if (head == nullptr)
        return true;
    else
        return false;
}

const int& IntList::front() const {
    return head->data;
}

const int& IntList::back() const {
    return tail->data;
}

ostream& operator<<(ostream& os, const IntList& ls) {
    IntNode *temp = ls.head;
    while (temp) {
        os << temp->data;
        temp = temp->next;
        if (temp != nullptr)
            os << " ";
    }
    return os;
}

void IntList::push_back(int value) {
    if (head == nullptr) {
        head = new IntNode(value);
        tail = head;
    } else {
        IntNode* temp = new IntNode(value);
        tail->next = temp;
        tail = temp;
    }
}

void IntList::clear() {
    while (head) {
        pop_front();
    }
    head = nullptr;
    tail = nullptr;
}

void IntList::selection_sort() {
    if (head != nullptr) {
        IntNode* i  = head;
        while (i != tail) {
            IntNode* min = i;
            IntNode* j = i;
            while (j) {
                if (j->data < min->data) {
                    min = j;
                }
                j = j->next;
            }
            swap(i->data, min->data);
            i = i->next;
        }
    }
}

void IntList::insert_ordered(int value) {
    if (head == nullptr) {
        push_back(value);
    } else {
        IntNode* temp = new IntNode(value);
        IntNode* i = head;
        IntNode* hold = nullptr;
        bool flag = false;
        while (i != nullptr && i->next != nullptr) {
            if ((temp->data >= i->data) && (temp->data <= i->next->data)) {
                hold = i->next;
                i->next = temp;
                temp->next = hold;
                flag = true;
                break;
            }
            i = i-> next;
        }
        if (!flag) {
            if (value <= head->data) {
                push_front(value);
            } else if (value >= tail->data) {
                push_back(value);
            }
        }
    }
}

void IntList::remove_duplicates() {
    if (head != nullptr) {
        IntNode* dupe  = head;
        IntNode* temp = nullptr;
        while (dupe != nullptr && dupe->next != nullptr) {
            IntNode* j = dupe;
            while (j->next) {
                if (j->next->data == dupe->data) {
                    temp = j->next;
                    if (j->next == tail)
                        tail = j;
                    j->next = temp->next;
                    delete temp;
                } else
                    j = j->next;
            }
            dupe = dupe->next;
        }
    }
}

// IntList(const IntList &cpy): the copy constructor. Make sure this performs deep copy.
// IntList & operator=(const IntList &rhs): the overloaded assignment operator. Make sure this performs deep copy.
// void push_back(int value): Inserts a data value (within a new node) at the back end of the list.
// void clear(): Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list.
// void selection_sort(): Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
// void insert_ordered(int value): Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.
// void remove_duplicates(): Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.
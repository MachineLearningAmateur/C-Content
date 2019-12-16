#include "SortedSet.h"

using namespace std;




// SortedSet(): The default constructor initializes an empty set.

// SortedSet(const SortedSet &): The copy constructor initializes the set to be a copy of the set passed in. Use the IntList copy constructor.

// SortedSet(const IntList &): A constructor that is passed an IntList instead of a SortedSet. It should initialize the set using the values in the IntList. Again, you can use the IntList copy constructor and then remove all of the duplicates and sort the remaining values.

// ~SortedSet(): The destructor needs to deallocate all dynamically allocated memory that the IntList destructor will not already deallocate. You may very well find that this function does not need to do anything.

// Accessors
// in(int data): This function returns true if the value in data is a member of the set, otherwise false.

// operator&: This function returns a SortedSet object that is the intersection of 2 SortedSet objects, the left and right operands of this binary operator. An intersection of 2 sets is a set of all elements that are in both sets. That is, all of the values that are in both the left operand and the right operand.
// sset1 = sset2 & sset3;


SortedSet::SortedSet() : IntList() {
}

SortedSet::SortedSet(const SortedSet& cpy) : IntList(cpy) {
}

SortedSet::SortedSet(const IntList& cpy) : IntList(cpy) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {
}

bool SortedSet::in(int data) {
    IntNode* temp = head;
    while (temp != nullptr) {
        if (data == temp->data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// operator|: This function returns a SortedSet object that is the union of 2 SortedSet objects, the left and right operands of this binary operator. A union of 2 sets is a set that consists of all of the distinct elements of both sets combined. That is, all of the values in both sets, minus any duplicates.
// sset1 = sset2 | sset3;

SortedSet& SortedSet::operator|(SortedSet& rhs) {
    SortedSet* temp = new SortedSet;
    IntNode* iterator = this->head;
    while(iterator != nullptr) {
        temp->push_back(iterator->data);
        iterator = iterator->next;
    }
    iterator = rhs.head;
    while(iterator != nullptr) {
        temp->push_back(iterator->data);
        iterator = iterator->next;
    }
    temp->remove_duplicates();
    return *temp;
}

// operator&: This function returns a SortedSet object that is the intersection of 2 SortedSet objects, the left and right operands of this binary operator. An intersection of 2 sets is a set of all elements that are in both sets. That is, all of the values that are in both the left operand and the right operand.
// sset1 = sset2 & sset3;
SortedSet& SortedSet::operator&(SortedSet& rhs) {
    SortedSet* temp = new SortedSet;
    IntNode* iterator = this->head;
    while(iterator != nullptr) {
        if (rhs.in(iterator->data)) {
            temp->push_back(iterator->data);
        }
        iterator = iterator->next;
    }
    return *temp;
}

void SortedSet::add(int data) {
    if (in(data)){
        return;
    }
    IntNode* temp = head;
    IntNode* val = nullptr;
    IntNode* nextNode = nullptr;
    while (temp != nullptr && temp->next != nullptr) {
        nextNode = temp->next;
        if (data > temp->data && data < nextNode->data) {
            val = new IntNode(data);
            temp->next = val;
            val->next = nextNode;
            return;
        }
        temp = temp->next;
    }
    
    if (head == nullptr)
        push_front(data);
    else if (data > tail->data) {
        push_back(data);
    } else if (data < head->data) {
        push_front(data);
    }
}


void SortedSet::push_front(int data) {
    if (head == nullptr) {
        head = new IntNode(data);
        tail = head;
    } else if (!in(data) && data < head->data) {
        IntNode *temp = new IntNode(data);
        temp->next = head;
        head = temp;
    } else if (!in(data)) {
        add(data);
    }
}

void SortedSet::push_back(int data) {
    if (head == nullptr) {
        head = new IntNode(data);
        tail = head;
    } else if (!in(data) && data > tail->data) {
        IntNode* temp = new IntNode(data);
        tail->next = temp;
        tail = temp;
    } else if (!in(data)) {
        add(data);
    }
    
}

void SortedSet::insert_ordered(int data) {
    add(data);
}

// operator|=: This function is the union-assign operator function. It returns a union of the left and right operands, but also sets the left operand's value to be that union as well.
// See operator| function specs above.

SortedSet& SortedSet::operator|=(SortedSet& rhs) {
    SortedSet* temp = new SortedSet(*this|rhs);
    IntNode* iterator = rhs.head;
    while(iterator != nullptr) {
        this->push_back(iterator->data);
        iterator = iterator->next;
    }
    return *temp;
}

// operator&=: This function is the intersection-assign operator function. It returns an intersection of the left and right operands, but also sets the left operand's value to be that intersection as well.

SortedSet& SortedSet::operator&=(SortedSet& rhs) {
    SortedSet* temp = new SortedSet(*this&rhs);
    IntNode* iterator = temp->head;
    this->clear();
    while (iterator != nullptr) {
        this->add(iterator->data);
        iterator = iterator->next;
    }
    return *temp;
}


//     add(int data): This function adds the value in data to the set. It needs to make sure data does not already exist in the set (no duplicates) and that it is inserted in the proper position (in ascending order).

// This must be an O(n) operation (essentially meaning only going through the list once).

// This means you cannot call remove_duplicates or selection_sort member functions within this function. Instead, this function must go through the list once (and only once) looking for the location to add the new value and then inserting it only if that location does not already have the value located there. This will be O(n) because you will visit each node in the list at most once. Recall, the remove_duplicates and selection_sort functions are O(n2) functions.

// So, this function is basically the insert_ordered function from your IntList, only you don't insert duplicates.

// push_front(int data): Override this function so that it inserts the value in data in the proper position (in ascending order) only if the value does not already exist in the set (no duplicates).

// In other words, this function should do exactly what add does. The only reason we are overriding this function is so that the push_front from the IntList is not inherited. A user of the SortedSet should not be able to just push any value onto the front of the list.

// In fact, since this function should do exactly what add does, this function should just call add to do the work for it.

// push_back(int data): Override this function so that it inserts the value in data in the proper position (in ascending order) only if the value does not already exist in the set (no duplicates).

// See specs for push_front above. The same rationale for overriding applies to this function.

// insert_ordered(int data): Override this function so that it does not insert duplicates.

// See specs for push_front above. The same rationale for overriding applies to this function.

#include <string>
#include <iostream>
#include "IntList.h"

using namespace std;

#ifndef __SORTEDSET_H__
#define __SORTEDSET_H__

// SortedSet(): The default constructor initializes an empty set.

// SortedSet(const SortedSet &): The copy constructor initializes the set to be a copy of the set passed in. Use the IntList copy constructor.

// SortedSet(const IntList &): A constructor that is passed an IntList instead of a SortedSet. It should initialize the set using the values in the IntList. Again, you can use the IntList copy constructor and then remove all of the duplicates and sort the remaining values.

// ~SortedSet(): The destructor needs to deallocate all dynamically allocated memory that the IntList destructor will not already deallocate. You may very well find that this function does not need to do anything.

// Accessors
// in(int data): This function returns true if the value in data is a member of the set, otherwise false.

// operator|: This function returns a SortedSet object that is the union of 2 SortedSet objects, the left and right operands of this binary operator. A union of 2 sets is a set that consists of all of the distinct elements of both sets combined. That is, all of the values in both sets, minus any duplicates.
// sset1 = sset2 | sset3;

// operator&: This function returns a SortedSet object that is the intersection of 2 SortedSet objects, the left and right operands of this binary operator. An intersection of 2 sets is a set of all elements that are in both sets. That is, all of the values that are in both the left operand and the right operand.
// sset1 = sset2 & sset3;

class SortedSet: public IntList {
  public:
    SortedSet();
    SortedSet(const SortedSet& cpy);
    SortedSet(const IntList& cpy);
    ~SortedSet();
    bool in(int data);
    SortedSet& operator|(SortedSet& rhs);
    SortedSet& operator&(SortedSet& rhs);
    void add(int data);
    void push_front(int data);
    void push_back(int data);
    void insert_ordered(int data);
    SortedSet& operator|=(SortedSet& rhs);
    SortedSet& operator&=(SortedSet& rhs);
    
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

// operator|=: This function is the union-assign operator function. It returns a union of the left and right operands, but also sets the left operand's value to be that union as well.

// See operator| function specs above.

// operator&=: This function is the intersection-assign operator function. It returns an intersection of the left and right operands, but also sets the left operand's value to be that intersection as well.

// See operator& specs above.
};

#endif
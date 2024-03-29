#include "IntVector.h"
#include <stdexcept>

// IntVector() - the Default constructor
// This function should set both the size and capacity of the IntVector to 0 and will not allocate any memory to store integers.
// (Make sure you do not have a dangling pointer.)

// IntVector(unsigned size, int value = 0)
// Sets both the size and capacity of the IntVector to the value of the parameter passed in and dynamically allocates an array of that size as well. This function should initialize all elements of the array to the value of the 2nd parameter.

// ~IntVector()
// The destructor is used to clean up (delete) any remaining dynamically-allocated memory. For this class, that will be the array pointed to by the int pointer called data.

// unsigned size() const
// This function returns the current size (not the capacity) of the IntVector object, which is the values stored in the sz data field.

// unsigned capacity() const
// This function returns the current capacity (not the size) of the IntVector object, which is the value stored in the cap data field.

// bool empty() const
// Returns whether the IntVector is empty (the sz field is 0).

// const int & at(unsigned index) const
// This function will return the value stored in the element at the passed in index position. Your function should throw an outofrange exception if an invalid index is passed in. An invalid index is an index greater than or equal to the size.
    
IntVector::IntVector() {
    sz = 0;
    cap = 0;
    data = nullptr;
}

IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    data = new int [sz]; 
    for (unsigned int i = 0; i < size; i++){
        data[i] = value;
    }
}

IntVector::~IntVector() {
    delete []data;
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    if (sz == 0) {
        return true;
    } else
        return false;
}

const int& IntVector::at(unsigned index) const {
    if (index >= sz)
        throw out_of_range("IntVector::at_range_check");
    else
        return data[index];
}

//new stuff

int& IntVector::at(unsigned index) {
    if (index >= sz)
        throw out_of_range("IntVector::at_range_check");
    else
        return data[index];
}

// void insert(unsigned index, int value)
// This function inserts data at position index. To do this, all values currently at position index and greater are shifted to the right by 1 (to the element right after its current position).

// Size will be increased by 1. However, If size will become larger than capacity, this function needs to first double the capacity. In other words, if capacity and size are both 20 when this function is called, this function must first increase the capacity to 40 and then it will be able to increase the size to 21.

// Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see above) to do this for you.

// This function should throw an out_of_range exception, passing it the string "IntVector::insert_range_check" if the index is too large. See bottom of specifications for more details on how to throw an exception and how to test that it works properly.

// void erase(unsigned index)
// This function removes the value at position index and shifts all of the values at positions greater than index to the left by one (to the element right before its current position).

// Size is decreased by 1.

// This function should throw an out_of_range exception, passing it the string "IntVector::erase_range_check" if the index is too large. See bottom of specifications for more details on how to throw an exception and how to test that it works properly.

void IntVector::insert(unsigned index, int value) {
    sz++;
    if (index >= sz) {
        throw out_of_range("IntVector::insert_range_check");
    }
    
    if (sz > cap) {
        expand();
    }
    for (unsigned int i = sz - 1; i > index; i--) {
        data[i] = data[i-1];
    }
    data[index] = value;
}
// sz: 10 -> 11, 10 9 8 7 6 5 4 3 2 1 0
void IntVector::erase(unsigned index) {
    if (index >= sz) {
        throw out_of_range("IntVector::erase_range_check");
    }
    sz--;
    for (unsigned int i = index; i < sz; i++) {
        data[i] = data[i+1];
    }
}
//sz: 10 -> 9, 10 9 8 7 6 5 4 3 2 1

const int& IntVector::front() const {
    return data[0];
}

int& IntVector::front() {
    return data[0];
}

const int& IntVector::back() const {
    return data[sz-1];
}

int& IntVector::back() {
    return data[sz-1];
}

// void assign(unsigned n, int value)
// Assigns new content to the vector object, dropping all the elements contained in the vector before the call and replacing them by those specified by the parameters. The new value of size will be n and all values stored in the vector will have the value of the 2nd parameter.

// If the new value of size will be larger than capacity, then this function must first expand capacity by either double (expand()) or by increasing the capacity by a specific amount (expand(n - cap)), whichever results in the largest capacity.
    
void IntVector::assign(unsigned n, int value) {
    if (n > cap) {
        if (cap * 2 >= n)
            expand();
        else
            expand(n-cap);
    }
    sz = n;
    for (unsigned int i = 0; i < n; i++) {
        data[i] = value;
    }
}

// void push_back(int value)
// This function inserts a value at the back end of the array.

// Size will be increased by 1. However, If size will become larger than capacity, this function needs to first increase the capacity. In other words, if capacity and size are both 20 when this function is called, capacity must first be increased to 40 and then size can be increased to 21.

// Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see above) to do this for you.

// void pop_back()
// This function just needs to decrease size by 1.

// This function will never thrown an exception. Calling pop_back on an empty vector will cause undefined behavior.

void IntVector::push_back(int value) {
    sz++;
    if (sz  > cap) {
        expand();
    }
    data[sz-1] = value;
}

void IntVector::pop_back() {
    sz = sz - 1;
}

void IntVector::clear() {
    sz = 0;
}

// void resize(unsigned size, int value = 0)
// This function resizes the vector to contain size elements.

// If size is smaller than the current size(sz), this function just reduces the value of sz to size.

// If size is greater than the current size(sz), then the appropriate number of elements are inserted at the end of the vector, giving all of the new elements the value passed in through the 2nd parameter (value).

// If the new value of size will be larger than capacity, then the capacity must first be expanded by either doubling (expand()) or by increasing the capacity by a specific amount (expand(size - cap)), whichever results in the largest capacity. Then, this function can then increase the size appropriately.

// void reserve(unsigned n)
// This function requests that the capacity (the size of the dynamically allocated array) be set to n at minimum. This informs the vector of a planned increase in size.

// This function should NOT ever reduce the size of the vector. If n is larger than the current capacity then the capacity should be expanded to n.

// A call to this function never affects the elements contained in the vector, nor the vector's size.
    
void IntVector::resize(unsigned size, int value) {
    if (size <= sz) {
        sz = size;
    } else if (size > sz) {
        if (size > cap) {
            if (cap * 2 < size) {
                expand(size-cap);
            } else
                expand();
        }
        for (unsigned int i = sz; i < size; i++) {
            data[i] = value;
        }
        sz = size;
    }
}
    
void IntVector::reserve(unsigned n) {
    if (n > cap) 
        expand(n-cap);     
}

// void expand()
// This function will double the capacity of the vector. This function should reallocate memory for the dynamically allocated array and update the value of capacity. Make sure your expand() function properly handles the case when capacity is 0 before calling expand(). This will be a special case within the expand() function.

// Make sure you don't create a memory leak here.

// void expand(unsigned amount)
// This function will expand the capacity of the vector by the amount passed in. This function should reallocate memory for the dynamically allocated array and update the value of capacity.

// Make sure you don't create a memory leak here.
    
void IntVector::expand() {
    if (cap == 0) {
        cap += 1;
        data = new int[cap];
    } else {
        cap = 2 * cap;
        int *temp = new int[cap];
        for (unsigned int i = 0; i < sz; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
}

void IntVector::expand(unsigned amount) {
    cap += amount;
    int *temp = new int[cap];
    for (unsigned int i = 0; i < sz; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
}
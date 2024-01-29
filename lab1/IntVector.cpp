#include "IntVector.h"
#include <iostream>
#include <stdexcept>

using namespace std;

IntVector::IntVector(unsigned capacity, int value) {
    if (capacity == 0) {
        _data = nullptr; //set it to nothing
        _capacity = 0; //set cap to 0
        _size = 0; //set size to 0
    }
    if (capacity > 0) {
        this-> _size = capacity;
        this-> _capacity = capacity;
        _data = new int[capacity];
        for (unsigned int i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    }
    else {}
}
IntVector::~IntVector() {
    delete[] _data; //free an array allocated with the new operator
}
unsigned IntVector::size() const {
    return this-> _size;
}
unsigned IntVector::capacity() const {
    return this-> _capacity;
}
bool IntVector::empty() const {
    if (_size == 0) {
        return true;
    }
    else {
        return false;
    }
}
const int & IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}
int& IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return _data[index];
    }
}
void IntVector::insert(unsigned index, int value) {
    //first check to see if its out of range
    if (index > this->_size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    //expand if the size is equal to our capacity
    if (this->_size == this->_capacity) {
        expand();
    }
    // Shift elements to the right
    for (unsigned i = this->_size; i > index; --i) { //use a negative loop to make it simpler
        _data[i] = _data[i - 1];
    }

    // Insert the new element
    _data[index] = value;
    this->_size = _size + 1;
}
void IntVector::erase(unsigned index) {
    //check for out of range
    if (index >= this->_size) {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i = index; i + 1 < _size; ++i) //loop to rewrite the value of indices
    {
        _data[i] = _data[i + 1];
    }
    _size = _size - 1; //reduce size
}
const int & IntVector::front() const {
    return _data[0];
}
int & IntVector::front() {
    return _data[0];
}
const int & IntVector::back() const {
    return _data[_size-1];
}
int & IntVector::back() {
    return _data[_size-1];
}
void IntVector::assign(unsigned n, int value) {
    this-> _size = n; //set size equal to n
    if (_size > _capacity) { //if n is greater than capacity increase the capacity
        expand(_size - _capacity); //the difference of the values = amount
    }
    for (unsigned i = 0; i < _size; ++i) {
        _data[i] = value; //all values of the list become equal to tbe given value
    }
}
void IntVector::push_back(int value) {
    if (_size == _capacity) {
        expand();
    }
    _data[_size] = value;
    this-> _size = _size + 1;   
}
void IntVector::pop_back() {
    if (_size > 0) {
        _size = _size -1;
    }
}
void IntVector::clear() {
    _size = 0;
}
void IntVector::resize(unsigned n, int value) {
    if (n < _size) { //If size is smaller than the current size(_size), this function just reduces the value of _size to size
        _size = n;
    }
    else if (n > _size) {
        if (n > _capacity) {
            if ((_capacity == 0) || (_capacity * 2 < n)) {
                expand(n - _capacity);
            }
            else {
                expand();
            }
        }
        for (unsigned i = _size; i < n; ++i) {
            _data[i] = value;
        }
        _size = n;
    }
}

void IntVector::reserve(unsigned n) {
    if (n > _capacity)
    {
        expand(n - _capacity);
    }
}
void IntVector::expand() {
    if (_capacity == 0) {
        this-> _capacity = 1;
    }
    else {
       this-> _capacity = this-> _capacity * 2;
    }
    int* newArr;
    newArr = new int[_capacity];
    for (unsigned i = 0; i < _size; i++) {
        newArr[i] = _data[i];
    }
    delete[] _data;
    _data = newArr;
}

void IntVector::expand(unsigned amount) {
    unsigned _new_capacity;
    _new_capacity = _capacity + amount;

    int* newArr;
    newArr = new int[_new_capacity];

    for (unsigned i = 0; i < _size; i++) {
        newArr[i] = _data[i];
    }
    //avoid dangling arrays
    delete[] _data;
    _data = newArr; //rewrite
    _capacity = _new_capacity; //assign with new capacity
}
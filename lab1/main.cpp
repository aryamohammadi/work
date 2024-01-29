#include "IntVector.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    cout << "Beginning tests." << endl;

    // Test default constructor without initial size and value
    IntVector testDefaultConstructor;
    if (testDefaultConstructor.size() != 0 || testDefaultConstructor.capacity() != 0) {
        cout << "Default constructor failed" << endl;
    }

    //Test constructor with initial size and value (0, 0)
    IntVector testDefault2;
    if (testDefault2.size() != 0 || testDefault2.capacity() != 0) {
        cout << "Default constructor failed (0,0)" << endl;
    }

    //Test constructor with inital size and value
    IntVector testDefaultWithInitial(10, 9);
    for (unsigned i = 0; i < testDefaultWithInitial.size(); ++i) {
        if (testDefaultWithInitial.at(i) != 9) {
            cout << "Default constructor failed (4,9)" << endl;
        }
        if (testDefaultWithInitial.size() != 10 || testDefaultWithInitial.capacity() != 10) {
            cout << "Default constructor failed (4,9)" << endl;
        }
        if (testDefaultWithInitial.front() != 9 || testDefaultWithInitial.back() != 9) {
            cout << "Default constructor failed (4,9)" << endl;
        }
    }

    //Test Default with big number
    IntVector testLarge(1028410, 1023);
    for (unsigned i = 0; i < testLarge.size(); ++i) {
        if (testLarge.at(i) != 1023) {
            cout << "Default constructor failed (1028410, 1023)" << endl;
        }
        if (testLarge.size() != 1028410 || testLarge.capacity() != 1028410) {
            cout << "Default constructor failed (1028410, 1023)" << endl;
        }
        if (testLarge.front() != 1023 || testLarge.back() != 1023) {
            cout << "Default constructor failed ((1028410, 1023)" << endl;
        }
    }

    return 0;
}

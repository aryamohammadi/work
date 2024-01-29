#include "SortedSet.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Testing started" << endl;

    SortedSet sortedset1;
    cout << "Testing Default Constructor, expecting empty: ";
    if (sortedset1.empty()) {
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
    }

    cout << "Testing Add and In for 1, 2, 3: ";
    sortedset1.add(1);
    sortedset1.add(2);
    sortedset1.add(3);
    if (sortedset1.in(1) && sortedset1.in(2) && sortedset1.in(3)) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    cout << "Testing adding duplicate (2): ";
    sortedset1.add(2);
    if (!sortedset1.in(2)) {
        cout << "Failed - Duplicate not allowed" << endl;
    } else {
        cout << "Passed" << endl;
    }

    cout << "Testing Copy Constructor: ";
    SortedSet sset2(sortedset1);
    if (sset2.in(1) && sset2.in(2) && sset2.in(3)) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    cout << "Testing Union with {4, 5}: ";
    SortedSet sortedset3;
    sortedset3.add(4);
    sortedset3.add(5);
    SortedSet ssetUnion = sortedset1 | sortedset3;
    if (ssetUnion.in(1) && ssetUnion.in(2) && ssetUnion.in(3) && ssetUnion.in(4) && ssetUnion.in(5)) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    cout << "Testing Intersection with {2, 3, 6}: ";
    SortedSet sset4;
    sset4.add(2);
    sset4.add(3);
    sset4.add(6);
    SortedSet ssetIntersection = sortedset1 & sset4;
    if (ssetIntersection.in(2) && ssetIntersection.in(3) && !ssetIntersection.in(1) && !ssetIntersection.in(6)) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    cout << "Testing Union-Assign with {4, 5}: ";
    sortedset1 |= sortedset3; 
    if (sortedset1.in(1) && sortedset1.in(2) && sortedset1.in(3) && sortedset1.in(4) && sortedset1.in(5)) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    cout << "Testing Intersection-Assign with {2, 3, 6}: ";
    sset4 &= sortedset1; 
    if (!sset4.in(1) && sset4.in(2) && sset4.in(3) && !sset4.in(6)) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    cout << "Testing completed" << endl;

    return 0;
}

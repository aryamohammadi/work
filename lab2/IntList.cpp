#include "IntList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList() {
    clear();
}
void IntList:: clear() {
    IntNode* current = head;
    while (current != nullptr) {
        IntNode* tempVal = current;
        current = current->next;
        delete tempVal;
    }
    head = tail = nullptr;
}
void IntList::push_front(int val) {
    if (this->head == nullptr) {
        this->tail = new IntNode (val);
        this-> head = this->tail;
    }
    else {
        IntNode *temp = new IntNode(val);
        temp->next = this->head;
        this->head = temp;
    }
}
void IntList:: pop_front() {
    if (head != nullptr) {
        IntNode* tempVal = head;
        head = head->next;
        delete tempVal;
        if (head == nullptr){
            tail = nullptr;
        }
    }
}
bool IntList::empty() const {
    return head == nullptr;
}
const int& IntList::front() const {
    return head->value;
}
const int & IntList::back() const{
    return tail->value;
}
ostream & operator<<(ostream &out, const IntList & rhs) {
    IntNode *current = rhs.head;
    
    if (current == nullptr) {
        return out;
    }
    while (current != nullptr) { //when the head is not empty
        out << current->value;
        if (current->next != nullptr) { //check if the next node is empty
            out << " "; // 
        }
        current = current->next; //move to the next node
    }
    return out;
}
IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    IntNode* current = cpy.head;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
}
IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        clear();
        IntNode *current = rhs.head;
        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }
    return *this; //reference to current obj
}

void IntList::push_back(int value) {
    IntNode* newNode = new IntNode(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void IntList::selection_sort() {
    if (head == nullptr || head == tail) {
        return;
    }
    IntNode* node = head;
    while (node != tail) {
        IntNode* minNode = node;
        IntNode* node2 = node->next;
        while (node2 != nullptr) {
            if (node2->value < minNode->value) {
                minNode = node2;
            }
            node2 = node2->next; 
        }
        if (minNode != node) {
            int tempVal = node->value;
            node->value = minNode->value;
            minNode->value = tempVal;
        }
        node = node->next;
    }
}

void IntList::insert_ordered(int value) {
    if (head == nullptr || value <= head->value) {
        push_front(value);
        return;
    }
    if (value >= tail->value) {
        push_back(value);
        return;
    }
    IntNode *newNode = new IntNode(value);
    IntNode *currentNode = head;
    IntNode *previousNode = nullptr;
    while (currentNode != nullptr && currentNode->value < value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    previousNode->next = newNode;
    newNode->next = currentNode;
}

void IntList::remove_duplicates() {
    if (head == nullptr || head == tail) {
        return;
    }
    IntNode *current = head;
    while (current != nullptr && current->next != nullptr) {
        IntNode *previous = current;
        IntNode *nextNode = current->next;
        while (nextNode != nullptr) {
            if (nextNode->value == current->value) {
                IntNode *duplicate = nextNode;
                nextNode = nextNode->next;
                previous->next = nextNode;
                if (duplicate == tail) {
                    tail = previous;
                }
                delete duplicate;
            }
            else {
                previous = nextNode;
                nextNode = nextNode->next;
            }
        }
        current = current->next;
    }
}


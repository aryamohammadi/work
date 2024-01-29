#include "SortedSet.h"

//Constructors & Destructor
SortedSet::SortedSet() : IntList() {
    head = 0;
    tail = 0;
}
SortedSet::SortedSet(const SortedSet& copyFrom) : IntList(copyFrom) {}
SortedSet::SortedSet(const IntList &list) : IntList(list) {
    remove_duplicates();
    selection_sort();
}
SortedSet::~SortedSet() {}

//Accessors
bool SortedSet::in(int value) const {
    IntNode* current = head;
    while (current != nullptr) {
        if (value == current->value) {
            return true;
        }
        current = current->next;
    }
    return false;
}
SortedSet SortedSet::operator|(const SortedSet &rhs) const {
    SortedSet sortedSet;

    IntNode* current = head;
    while (current != nullptr) {
        sortedSet.add(current->value);
        current = current->next;
    }
    current = rhs.head;
    while (current != nullptr) {
        sortedSet.add(current->value);
        current = current->next;
    }
    return sortedSet;
}
SortedSet SortedSet::operator&(const SortedSet &rhs) const {
    SortedSet sortedSet;
    IntNode *currRight = rhs.head;
    while (currRight != nullptr) {
        if (in(currRight->value)) {
            sortedSet.add(currRight->value);
        }
        currRight = currRight->next;
    }
    return sortedSet;
}

void SortedSet::add(int value) {
    if (empty() || value < head->value) {
        IntList::push_front(value);
        return;
    }
    if (value > tail->value) {
        IntList::push_back(value);
        return;
    }
    if (value == head->value || value == tail->value) {
        return;
    }
    IntNode* temp = head;
    while (temp->next != nullptr && temp->next->value < value) {
        temp = temp->next;
    }
    if (temp->next == nullptr || temp->next->value > value) {
        IntNode* newNode = new IntNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }
}

void SortedSet::push_front(int value) {
    add(value);
}
void SortedSet::insert_ordered(int value) {
    add(value);
}

SortedSet& SortedSet::operator&=(const SortedSet &m) {
    SortedSet List;
    IntNode *index = m.head;
    while (index != nullptr) {
        if (in(index->value)) {
            List.push_back(index->value);
        }
        index = index->next;
    }
    *this = List;
    return *this;
}

SortedSet& SortedSet::operator|=(const SortedSet &rhs) {
    *this = *this | rhs;
    return *this;
}

SortedSet& SortedSet::operator&=(const SortedSet &rhs) {
    *this = *this & rhs;
    return *this;
}

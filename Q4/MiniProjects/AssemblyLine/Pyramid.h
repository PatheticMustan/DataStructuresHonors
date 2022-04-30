#include <bits/stdc++.h>
using namespace std;

#ifndef STACK_H
#define STACK_H

/*
This is just a linked list but you can only push and pop
*/

class Pyramid {
    private:
        int value = -1;
        Pyramid* next = NULL;
        
        // setters
        void setValue(int v) { value = v; }
        void setNext(Pyramid* n) { next = n; }
    
    public:
        // constructors
        Pyramid() { value = -1; next = NULL; }
        Pyramid(int v) { value = v; next = NULL; }

        // getters
        int getValue() { return value; }
        Pyramid* getNext() { return next; }

        // util
        void push(int v) {
            if (getValue() == -1) {
                setValue(v);
            } else {
                Pyramid* end = this;
                while (end->getNext() != NULL) end = end->getNext();
                end->next = new Pyramid(v);
            }
        }

        int pop() {
            if (getNext() == NULL) {
                int val = getValue();
                setValue(-1);
                return val;
            } else {
                Pyramid* end = this;
                while (end->getNext()->getNext() != NULL) end = end->getNext();
                int val = end->getNext()->getValue();
                end->setNext(NULL);

                return val;
            }

            return -1;
        }

        int peek() {
            if (getNext() == NULL) {
                return getValue();
            } else {
                Pyramid* end = this;
                while (end->getNext() != NULL) end = end->getNext();
                return end->getValue();
            }

            return -1;
        }
};

ostream& operator<<(ostream& stream, Pyramid* head) {
    stream << "[";
    while (head != NULL) {
        stream << head->getValue();
        head = head->getNext();
        if (head != NULL) cout << ", ";
    }
    stream << "]";
    return stream;
}

#endif
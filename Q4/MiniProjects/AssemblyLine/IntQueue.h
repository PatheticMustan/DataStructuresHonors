#include <bits/stdc++.h>
using namespace std;

#ifndef INTQUEUE_H
#define INTQUEUE_H

/*
This is just a linked list but you can only push and pop
*/

class IntQueue {
    private:
        int value = -1;
        IntQueue* next = NULL;
        
        // setters
        void setValue(int v) { value = v; }
        void setNext(IntQueue* n) { next = n; }
    
    public:
        // constructors
        IntQueue() { value = -1; next = NULL; }
        IntQueue(int v) { value = v; next = NULL; }

        // getters
        int getValue() { return value; }
        IntQueue* getNext() { return next; }
        
        // util
        // append to end
        void enqueue(int v) {
            if (getValue() == -1) {
                setValue(v);
            } else {
                IntQueue* end = this;
                while (end->getNext() != NULL) end = end->getNext();
                end->next = new IntQueue(v);
            }
        }

        // move head up one position
        int dequeue() {
            int val = getValue();
            if (getNext() == NULL) {
                setValue(-1);
                return val;
            } else {
                // so simple..!?!?
                setValue(getNext()->getValue());
                setNext(getNext());
                return val;
            }

            return -1;
        }

        int peek() {
            return getValue();
        }
};

ostream& operator<<(ostream& stream, IntQueue* head) {
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
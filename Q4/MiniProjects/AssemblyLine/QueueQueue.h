#include <bits/stdc++.h>
#include "Pyramid.h"
using namespace std;

#ifndef QUEUEQUEUE_H
#define QUEUEQUEUE_H

class QueueQueue {
    private:
        Pyramid* value = NULL;
        QueueQueue* next = NULL;
        
        // setters
        void setValue(Pyramid* v) { value = v; }
        void setNext(QueueQueue* n) { next = n; }
    
    public:
        // constructors
        QueueQueue() { value = NULL; next = NULL; }
        QueueQueue(Pyramid* v) { value = v; next = NULL; }

        // getters
        Pyramid* getValue() { return value; }
        QueueQueue* getNext() { return next; }
        
        // util
        // append to end
        void enqueue(Pyramid* v) {
            if (getValue() == NULL) {
                setValue(v);
            } else {
                QueueQueue* end = this;
                while (end->getNext() != NULL) end = end->getNext();
                end->next = new QueueQueue(v);
            }
        }

        // move head up one position
        Pyramid* dequeue() {
            if (getNext() == NULL) {
                Pyramid* val = getValue();
                setValue(NULL);
                return val;
            } else {
                // so simple..!?!?
                Pyramid* val = getNext()->getValue();
                setValue(getNext()->getValue());
                setNext(getNext()->getNext());
                return val;
            }

            return NULL;
        }

        Pyramid* peek() {
            return getValue();
        }
};

ostream& operator<<(ostream& stream, QueueQueue* head) {
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
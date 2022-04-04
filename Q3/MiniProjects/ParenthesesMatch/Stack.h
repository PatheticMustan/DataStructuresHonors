#include <bits/stdc++.h>
using namespace std;

#ifndef STACK_H
#define STACK_H

/*
This is just a linked list but you can only push and pop
*/

class Stack {
    private:
        string value = "";
        Stack* next = NULL;
        
        // getters
        string getValue() { return value; }
        Stack* getNext() { return next; }
        // setters
        void setValue(string v) { value = v; }
        void setNext(Stack* n) { next = n; }
    
    public:
        // constructors
        Stack(string v) {
            value = v;
            next = NULL;
        }

        // util
        void push(string v) {
            if (getValue() == "") {
                setValue(n->getValue)
            }
            Stack* end = NULL;
            while (end->getNext() != NULL) end = end->getNext();
            end->next = n;
        }

        string* remove() {
            // previous, this, next
            Stack* end = NULL;
            while (end->getNext() != NULL) end = end->getNext();
            end->next = ;
            return this;
        }
};

ostream& operator<<(ostream& stream, Stack* head) {
    stream << "[";
    while(head != NULL) {
        stream << head->getValue();
        head = head->getNext();
        if(head != NULL)
            cout << ", ";
    }
    stream << "]" << endl;
    return stream;
}

#endif
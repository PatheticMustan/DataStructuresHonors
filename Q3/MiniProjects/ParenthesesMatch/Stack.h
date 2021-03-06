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
        
        // setters
        void setValue(string v) { value = v; }
        void setNext(Stack* n) { next = n; }
    
    public:
        // constructors
        Stack(string v) {
            value = v;
            next = NULL;
        }

        // getters
        string getValue() { return value; }
        Stack* getNext() { return next; }

        // util
        void push(string v) {
            if (getValue() == "") {
                setValue(v);
            } else {
                Stack* end = this;
                while (end->getNext() != NULL) end = end->getNext();
                end->next = new Stack(v);
            }
        }

        string pop() {
            if (getNext() == NULL) {
                string val = getValue();
                setValue("");
                return val;
            } else {
                Stack* end = this;
                while (end->getNext()->getNext() != NULL) end = end->getNext();
                string val = end->getNext()->getValue();
                end->setNext(NULL);

                return val;
            }

            return "";
        }

        string peek() {
            if (getNext() == NULL) {
                return getValue();
            } else {
                Stack* end = this;
                while (end->getNext() != NULL) end = end->getNext();
                return end->getValue();
            }

            return "";
        }
};

ostream& operator<<(ostream& stream, Stack* head) {
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
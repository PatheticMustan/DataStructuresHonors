#include <bits/stdc++.h>
using namespace std;

#ifndef BigMath_H
#define BigMath_H

class BigMath {
    private:
        int value = 0;
        BigMath* next = nullptr;
    
    public:
        // constructors
        BigMath(int v, BigMath* n) {
            value = v;
            next = n;
        }

        // getters
        int getValue() { return value; }
        BigMath* getNext() { return next; }
        // setters
        void setValue(int val) { value = val; } //val val val! I know a person named Val! Sadly their full name wasn't value
        void setNext(BigMath* node) { next = node; }

        // util methods
        BigMath* copyNode(BigMath* arg) {
            return new BigMath(arg->getValue(), arg->getNext());
        }
        BigMath* copyList(BigMath* arg) {
            if (arg->getNext() == NULL) return copyNode(arg);

            return new BigMath(arg->getValue(), copyList(arg->getNext()));
        }
        BigMath* rest(BigMath* arg) {
            return copyList(arg->getNext());
        }
        // returns the value of the first node, or NULL if the list is empty
        int first(BigMath* head) {
            return head->getValue();
        }
        // returns the value of the second node, or NULL if the list is empty or if there is only one node.
        // hint: second could call the first of rest.
        int second(BigMath* head) {
            if (head->getNext() == NULL) return NULL;

            return head->getNext()->getValue();
        }
        //returns a reference to the last node in the list, or NULL if the list is empty.
        BigMath* pointerToLast(BigMath* head) {
            BigMath* uwu = head;

            while (uwu->getNext() != NULL) {
                uwu = uwu->getNext();
            }

            return uwu;
        }
        //returns a copy of the last node (not just its value!). copyofLast can be recursive.
        BigMath* copyOfLast(BigMath* head) {
            return copyNode(pointerToLast(head));
        }
        //returns a reference to a list whose first node's value is specified by the argument, and the
        //first node's next links to the original list.
        BigMath* insertFirst(BigMath* head, int arg) {
            return new BigMath(arg, head);
        }
        //returns a reference to a list whose last node&#39;s value is specified by the argument, such
        //that this last node has been appended to the original list and had its next is set to NULL
        BigMath* insertLast(BigMath* head, int arg) {
            head->pointerToLast(head)->next = new BigMath(arg, NULL);

            return head;
        }
};

#endif
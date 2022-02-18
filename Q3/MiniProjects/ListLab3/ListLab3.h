#include <bits/stdc++.h>
using namespace std;

#ifndef LISTNODE_H
#define LISTNODE_H

/*
A doubly-linked list is a linked list where each node has access to both the next node and the previous node.

Create ListLab3.h that demonstrates a doubly-linked list.
- Your file must include methods to add a node at the beginning or specified position of the list
    (called add...no additional parameter is beginning; additional parameter is position)
- and remove a node at the beginning or specified position of the list
    (called remove; same information as above).

Standard rules apply for formatting and usability.
    4 points for documentation,
    4 points for user-friendliness,
    20 points for the required methods.

You must also include operators for displaying your list when printed with cout.
*/

class ListNode {
    private:
        string value = "";
        ListNode* next = nullptr;
        ListNode* previous = nullptr;
    
    public:
        // constructors
        ListNode(string v, ListNode* n) {
            value = v;
            next = n;
            previous = NULL;

            if (n != NULL) n->previous = this;
        }
        ListNode(string v, ListNode* n, ListNode* p) {
            value = v;
            next = n;
            previous = p;
        }

        // getters
        string getValue() { return value; }
        ListNode* getNext() { return next; }
        ListNode* getPrevious() { return previous; }
        // setters
        void setValue(string v) { value = v; }
        void setNext(ListNode* n) { next = n; }
        void setPrevious(ListNode* n) { previous = n; }

        // util
        // Your file must include methods to add a node at the beginning or specified position of the list
        //      (called add...no additional parameter is beginning; additional parameter is position)
        ListNode* add(ListNode* n) {
            n->setNext(this);
            setPrevious(n);

            return previous;
        }
        ListNode* add(ListNode* n, int index) {
            ListNode* h = this;
            while ((h->getNext() != NULL) && (index-- != 0)) h = h->getNext();
            n->setPrevious(h);
            n->setNext(h->next);
            h->setNext(n);

            return this;
        }

        // and remove a node at the beginning or specified position of the list
        //      (called remove; same information as above).
        ListNode* remove() {
            if (getNext() == NULL) return NULL;

            getNext()->setPrevious(NULL);
            return getNext();
        }
        ListNode* remove(int index) {
            if (index == 0) return remove();
            
            ListNode* h = this;
            while ((h->getNext() != NULL) && (index-- != 0)) {
                h = h->getNext();
            }
            
            h->previous->setNext(h->next);
            if (h->next != NULL) h->next->setPrevious(h->previous);
            h->setPrevious(NULL);
            return this;
        }
};

#endif
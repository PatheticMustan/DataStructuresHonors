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

            n->previous = this;
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

        // util
        // Your file must include methods to add a node at the beginning or specified position of the list
        //      (called add...no additional parameter is beginning; additional parameter is position)
        ListNode* add(ListNode* n) {
            n->next = this;
            this->previous = n;

            return this;
        }
        ListNode* add(ListNode* n, int index) {
            ListNode* h = this;
            while ((h->getNext() != NULL) && (index-- != 0)) h = h->getNext();
            h->next = n;
            n->previous = h;

            return this;
        }
        ListNode* addToEnd(ListNode* n) {
            ListNode* h = this;
            while (h->getNext() != NULL) h = h->getNext();
            h->next = n;
            n->previous = h;

            return this;
        }

        // and remove a node at the beginning or specified position of the list
        //      (called remove; same information as above).
        ListNode* remove() {
            if (this->getNext() == NULL) return NULL;

            getNext()->previous = NULL;
            return getNext();
        }
        ListNode* remove(int index) {
            if (index == 0) return this->remove();
            
            ListNode* h = this;
            while ((h->getNext() != NULL) && (index-- != 0)) h = h->getNext();

            getNext()->previous = NULL;
            return getNext();
        }
};

#endif
#include <bits/stdc++.h>
using namespace std;

#ifndef LISTNODE_H
#define LISTNODE_H

/*
A circular Linked List is a variation of a Linked List in which the first element points to the last element
and the last element points to the first element.

Create ListLab4.h that demonstrates a circular doubly-linked list.
- Your file must include methods to add a node at a specified position of the list
- and remove a node at a specified position of the list.
- In addition, please include methods to printForward from a starting position and printBackward from a
    starting position (as measured from your insertion point from the beginning of the creation of the list).

Standard rules apply for formatting and usability.
- 4 points for documentation,
- 4 points for user-friendliness,
- 20 points for the required methods.

You must also include operators for displaying your list when printed with cout.
*/

class ListNode {
    private:
        string value = "";
        ListNode* next = this;
        ListNode* previous = this;
        
        // only we should be modifying next and previous
        void setNext(ListNode* n) { next = n; }
        void setPrevious(ListNode* n) { previous = n; }
    
    public:
        // constructors
        ListNode(string v, ListNode* n) {
            value = v;

            /** There are four values we need to edit
             *          this.next = loopStart
             *      this.previous = loopEnd
             * loopStart.previous = this
             *       loopEnd.next = this
             * 
             * this      = this
             * loopStart = this | n
             * loopEnd   = this | n.previous
             **/

            ListNode* loopStart = (n == NULL)? this : n;
            ListNode* loopEnd = loopStart->previous;

            next = loopStart;
            previous = loopEnd;
            loopStart->previous = this;
            loopEnd->next = this;
        }

        // getters
        string getValue() { return value; }
        ListNode* getNext() { return next; }
        ListNode* getPrevious() { return previous; }
        // setters
        void setValue(string v) { value = v; }

        // util
        // Your file must include methods to add a node at the beginning or specified position of the list
        //      (called add...no additional parameter is beginning; additional parameter is position)
        ListNode* add(ListNode* n) {
            // n -> thisnode
            // (n) (last of n, n.prev) (this) (last of this, this.prev)
            ListNode* ns = n;
            ListNode* ne = n->previous;
            ListNode* ts = this;
            ListNode* te = this->previous;

            ns->previous = te;
            ne->next = ts;
            ts->previous = ne;
            te->next = ns;

            return previous;
        }
        ListNode* add(ListNode* n, int index) {
            // index 0 is just normal add, return the new head
            if (index == 0) {
                add(n);
                return n;
            }

            // run down the new position, add
            ListNode* h = this;
            while (index != 0) {
                if (index > 0) {
                    index--;
                    h = h->getNext();
                } else {
                    index++;
                    h = h->getPrevious();
                }
            }
            h->add(n);

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

        // print methods
        void printForward() { printForward(0); }
        void printForward(int index) {
            ListNode* h = this;
            while (index--) h = h->getNext();
            ListNode* head = h;

            cout << "[";
            do {
                cout << h->getValue();
                h = h->getNext();
                if(h != head) cout << ", ";
            } while (h != head);
            cout << "]" << endl;
        }
        void printBackward() { printBackward(0); }
        void printBackward(int index) {
            ListNode* h = this;
            while (index--) h = h->getNext();
            ListNode* head = h;

            cout << "[";
            do {
                cout << h->getValue();
                h = h->getPrevious();
                if(h != head) cout << ", ";
            } while (h != head);
            cout << "]" << endl;
        }
};

ostream& operator<<(ostream& stream, ListNode* head) {
    ListNode* h = head;

    stream << "[";
    do {
        stream << h->getValue();
        h = h->getNext();
        if (h != head) stream << ", ";
    } while (h != head);
    stream << "]" << endl;

    return stream;
}

#endif
#include <bits/stdc++.h>
using namespace std;

#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode {
    private:
        string value = "";
        ListNode* next = nullptr;
    
    public:
        // constructors
        ListNode(string v, ListNode* n) {
            value = v;
            next = n;
        }

        // getters
        string getValue() { return value; }
        ListNode* getNext() { return next; }

        // util methods
        ListNode* copyNode(ListNode* arg) {
            return new ListNode(arg->getValue(), arg->getNext());
        }
        ListNode* copyList(ListNode* arg) {
            if (arg->getNext() == NULL) return copyNode(arg);

            return new ListNode(arg->getValue(), copyList(arg->getNext()));
        }
        ListNode* rest(ListNode* arg) {
            return copyList(arg->getNext());
        }
        // returns the value of the first node, or NULL if the list is empty
        string first(ListNode* head) {
            return head->getValue();
        }
        // returns the value of the second node, or NULL if the list is empty or if there is only one node.
        // hint: second could call the first of rest.
        string second(ListNode* head) {
            if (head->getNext() == NULL) return NULL;

            return head->getNext()->getValue();
        }
        //returns a reference to the last node in the list, or NULL if the list is empty.
        ListNode* pointerToLast(ListNode* head) {
            ListNode* uwu = head;

            while (uwu->getNext() != NULL) {
                uwu = uwu->getNext();
            }

            return uwu;
        }
        //returns a copy of the last node (not just its value!). copyofLast can be recursive.
        ListNode* copyOfLast(ListNode* head) {
            return copyNode(pointerToLast(head));
        }
        //returns a reference to a list whose first node's value is specified by the argument, and the
        //first node's next links to the original list.
        ListNode* insertFirst(ListNode* head, string arg) {
            return new ListNode(arg, head);
        }
        //returns a reference to a list whose last node&#39;s value is specified by the argument, such
        //that this last node has been appended to the original list and had its next is set to NULL
        ListNode* insertLast(ListNode* head, string arg) {
            head->pointerToLast(head)->next = new ListNode(arg, NULL);

            return head;
        }
};

#endif
#include <bits/stdc++.h>
using namespace std;

#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode {
    private:
        string word = "";
        int count = 0;
        ListNode* next = NULL;
    
    public:
        // constructors
        ListNode(string w, ListNode* n) {
            word = w;
            count = 0;
            next = n;
        }

        // getters
        string getWord() { return word; }
        int getCount() { return count; }
        ListNode* getNext() {
            if (next == NULL) return NULL;
            return next;
        }
        // setters
        void increment() { count++; }
        void setNext(ListNode* n) { next = n; }

        // util methods
        ListNode* copyNode(ListNode* arg) {
            return new ListNode(arg->getWord(), arg->getNext());
        }
        ListNode* copyList(ListNode* arg) {
            if (arg->getNext() == NULL) return copyNode(arg);
            return new ListNode(arg->getWord(), copyList(arg->getNext()));
        }
        //returns a reference to the last node in the list, or NULL if the list is empty.
        ListNode* pointerToLast(ListNode* head) {
            ListNode* uwu = head;

            while (uwu->getNext() != NULL) {
                uwu = uwu->getNext();
            }

            return uwu;
        }

        void addWord(ListNode* head, string word) {
            // lowercase, why can't we just have .toLower()?
            for (int i=0; i<word.length(); i++) word[i] = tolower(word[i]);

            bool found = false;
            ListNode* h = head;
            ListNode* end = head->pointerToLast(head);

            while (true) {
                if (h->getWord().compare(word) == 0) {
                    h->increment();
                    found = true;
                } else if (h->getWord().compare(word) > 0) {

                    ListNode* newWord = new ListNode(word, h);
                    newWord->increment();

                    ListNode* hh = head;
                    while (hh->getNext() != h) hh = hh->getNext();
                    hh->setNext(newWord);
                    
                    found = true;
                }

                if (found == true) break;
                if (h == end) break;

                h = h->getNext();
            }

            if (found == false) {
                ListNode* newWord = new ListNode(word, NULL);
                newWord->increment();
                h->setNext(newWord);
            }
        }
};

#endif
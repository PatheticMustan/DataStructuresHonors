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
        ListNode* insertMiddle(ListNode* head, string data, int position) {
            ListNode* node = new ListNode(data, NULL);
            if (position == 0) {
                node->next = (head);
                return node;
            }

            ListNode* e = head;
            // i learned this trick from my javascript friends
            while (position --> 1) {
                // if you reach the end of the list early, just stick it on the end
                if (e->getNext() == NULL) {
                    e->next = node;
                    return head;
                }
                e = e->getNext();
            }

            ListNode* rest = e->getNext();
            e->next = node;
            node->next = rest;

            return head;
        }

        void addWord(ListNode* head, string word) {
            // lowercase, why can't we just have .toLower()?
            for (int i=0; i<word.length(); i++) word[i] = tolower(word[i]);

            bool found = false;
            ListNode* h = head;

            while (h->getNext()!=NULL) {
                cout << h->getWord() << "," << word << "," << h->getWord().compare(word) << endl;

                if (h->getWord().compare(word) == 0) {
                    h->increment();
                    found = true;
                } else if (h->getWord().compare(word) > 0) {
                    cout << 1 << endl;

                    ListNode* newWord = new ListNode(word, h);
                    newWord->increment();

                    ListNode* hh = head;
                    while (hh->getNext() != h) hh = hh->getNext();
                    hh->setNext(newWord);
                    
                    found = true;
                }

                if (found == true) break;

                h = h->getNext();
            }

            if (found == false) {
                cout << 2 << endl;
                ListNode* newWord = new ListNode(word, NULL);
                newWord->increment();
                h->setNext(newWord);
            }
        }
};

#endif
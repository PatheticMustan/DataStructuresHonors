#include <bits/stdc++.h>
using namespace std;

#ifndef BIGMATH_H
#define BIGMATH_H

class BigMath {
    private:
        int digit = 0;
        BigMath* next = nullptr;
    
    public:
        // constructors
        BigMath(int v, BigMath* n) { digit = v; next = n; }
        BigMath(string data) {
            // go backwards, so "12345" would be stored as [5, 4, 3, 2, 1]
            // this is to make addition/subtraction easier
			setDigit(data[data.length()-1] - '0');
			BigMath* tail = this;

			for (int i=data.length()-2; i>=0; i--) {
				tail->setNext(new BigMath(data[i]-'0', NULL));
				tail = tail->getNext();
			}
		}

        // getters
        int getDigit() { return digit; }
        BigMath* getNext() { return next; }
        // setters
        void setDigit(int d) { digit = d; }
        void setNext(BigMath* node) { next = node; }

        // COPIED FROM MY EARLIER LISTLAB PROJECT
        // while technically yes this is re-used code, it's my code, so it's all fine!
        // util methods
        BigMath* copyNode(BigMath* arg) {
            return new BigMath(arg->getDigit(), arg->getNext());
        }
        BigMath* copyList(BigMath* arg) {
            if (arg->getNext() == NULL) return copyNode(arg);
            return new BigMath(arg->getDigit(), copyList(arg->getNext()));
        }
        BigMath* rest(BigMath* arg) {
            return copyList(arg->getNext());
        }
        // returns the Digit of the first node, or NULL if the list is empty
        int first(BigMath* head) {
            return head->getDigit();
        }
        // returns the Digit of the second node, or NULL if the list is empty or if there is only one node.
        // hint: second could call the first of rest.
        int second(BigMath* head) {
            if (head->getNext() == NULL) return NULL;
            return head->getNext()->getDigit();
        }
        //returns a reference to the last node in the list, or NULL if the list is empty.
        BigMath* pointerToLast(BigMath* head) {
            BigMath* uwu = head;
            while (uwu->getNext() != NULL) uwu = uwu->getNext();
            return uwu;
        }

        BigMath* pointerBeforeLast(BigMath* head) {
            BigMath* uwu = head;
            while (uwu->getNext() != NULL) {
                if (uwu->getNext()->getNext() != NULL) {
                    uwu = uwu->getNext();
                }
            }
            return uwu;
        }
        //returns a copy of the last node (not just its Digit!). copyofLast can be recursive.
        BigMath* copyOfLast(BigMath* head) {
            return copyNode(pointerToLast(head));
        }
        //returns a reference to a list whose first node's Digit is specified by the argument, and the
        //first node's next links to the original list.
        BigMath* insertFirst(BigMath* head, int arg) {
            return new BigMath(arg, head);
        }
        //returns a reference to a list whose last node's Digit is specified by the argument, such
        //that this last node has been appended to the original list and had its next is set to NULL
        BigMath* insertLast(BigMath* head, int arg) {
            return pointerToLast(head)->next = new BigMath(arg, NULL);
        }

        // custom operators
        BigMath* operator+ (BigMath& other);
        BigMath* operator- (BigMath& other);
        friend ostream& operator<< (ostream &strm, BigMath *c);
        friend ostream& operator<< (ostream &strm, BigMath &c);
};

// toString
ostream& operator<< (ostream &strm, BigMath *c) {
    int length = 0;

    // get length of string
    BigMath* tail = c;
    while(tail != NULL) {
		length++;
        tail = tail->getNext();
	}
    // allocate a string, go backwards
    string result(length, 'Q');
    tail = c;
    for (int i=0; i<length; i++) {
        result[length-i-1] = tail->getDigit() + '0';
        tail = tail->getNext();
    }

    return strm << result;
}
ostream& operator<< (ostream &strm, BigMath &c) {
    return strm << &c;
}



BigMath* BigMath::operator+ (BigMath& other) {
    BigMath* result = new BigMath(0, NULL);
    BigMath* resultTail = result;

    BigMath* a = copyList(this);
    BigMath* b = copyList(&other);

    // add
    while (a!=NULL || b!=NULL) {
        int av = (a!=NULL)? a->getDigit() : 0;
        int bv = (b!=NULL)? b->getDigit() : 0;
        
        int r = av + bv;
        resultTail->setDigit(r);

        if (a != NULL) a = a->getNext();
        if (b != NULL) b = b->getNext();
        resultTail->setNext(new BigMath(0, NULL));
        resultTail = resultTail->getNext();
    }

    // carry over
    resultTail = result;
    int carryOver = 0;
    while (resultTail != NULL) {
        resultTail->setDigit(resultTail->getDigit() + carryOver);
        carryOver = (resultTail->getDigit() > 9)? 1 : 0;
        resultTail->setDigit(resultTail->getDigit() % 10);

        resultTail = resultTail->getNext();
    }

    return result;
};

BigMath* BigMath::operator- (BigMath& other) {
    BigMath* result = new BigMath(0, NULL);
    BigMath* resultTail = result;

    BigMath* a = copyList(this);
    BigMath* b = copyList(&other);

    // add
    while (a!=NULL || b!=NULL) {
        int av = (a!=NULL)? a->getDigit() : 0;
        int bv = (b!=NULL)? b->getDigit() : 0;
        
        int r = av - bv;
        resultTail->setDigit(r);

        if (a != NULL) a = a->getNext();
        if (b != NULL) b = b->getNext();
        resultTail->setNext(new BigMath(0, NULL));
        resultTail = resultTail->getNext();
    }

    // carry over
    resultTail = result;
    int carryOver = 0;
    while (resultTail != NULL) {
        resultTail->setDigit(resultTail->getDigit() + carryOver);
        carryOver = (resultTail->getDigit() > 9)? 1 : 0;
        resultTail->setDigit(resultTail->getDigit() % 10);

        resultTail = resultTail->getNext();
    }

    return result;
};


#endif
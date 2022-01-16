#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

#ifndef BIGMATH_H
#define BIGMATH_H

class BigMath {
    private:
        bool isNegative = false;
        int length = 0;
        ListNode* numbers = NULL;
    
    public:
        BigMath(string data) {
            ListNode* head = new ListNode(-1, NULL);
            ListNode* tail = head;
            length = data.length();

            // convert string to integers, why does c++ make this so hard
            for (int i=data.length(); i>=0; i--) {
                string n = "0123456789";
                for (int o=0; o<10; o++) {
                    if (n[o] == data[i]) {
                        tail->setValue(o);
                        if (i != data.length()-1) {
                            tail->setNext(new ListNode(-1, NULL));
                            tail = tail->getNext();
                        }
                    }
                }
            }

            numbers = head;
        }

        // getters
        ListNode* getRaw() { return numbers; }
        int getLength() { return length; }

    	// custom operators
	    BigMath* operator+ (BigMath& other) {
    	    // 411 + 989 = 1400
	    	
    	    return new BigMath("123");
	    };

        BigMath* operator- (BigMath& other) {
            return new BigMath("123");
        };
};

// toString
ostream& operator<< (ostream &strm, BigMath &c) {
	ListNode* head = c.getRaw();
    while(head != NULL) {
	    cout << head->getValue();
    	head = head->getNext();
	}
    return strm;
}
ostream& operator<< (ostream &strm, BigMath *c) {
    ListNode* head = c->getRaw();
    while(head != NULL) {
		cout << head->getValue();
		head = head->getNext();
	}
    return strm;
}

#endif
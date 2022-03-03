#include <iostream>
#include "ListLab4.h"
using namespace std;

int main() {
    ListNode* head = new ListNode("aaaaa", NULL);
    head->add(new ListNode("bbbbb", NULL));
    head->add(new ListNode("ccccc", NULL));
    head->add(new ListNode("eeeee", NULL));
    head->add(new ListNode("ddddd", NULL), 3);
    new ListNode("fffff", head);
    
    head->printForward();
    head->printBackward();

    
    /*

    head = head->add(new ListNode("nat", NULL), 3);
    cout << head;

    head = head->remove();
    head = head->remove(0);
    head = head->remove(1);
    head = head->remove(4);
    head = head->remove(4);
    cout << head;

    head->printForward();
    head->printForward(1);
    head->printBackward();
    head->printBackward(1);
    */

    return 0;
}
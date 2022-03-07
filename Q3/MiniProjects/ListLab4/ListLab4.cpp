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

    head = head->add(new ListNode("nat", NULL), 0);
    cout << head;
    head->printBackward();

    
    head = head->remove();
    head->printForward();
    head->printBackward();

    head = head->remove(0);
    head->printForward();
    head->printBackward();

    head = head->remove(1);
    head->printForward();
    head->printBackward();
    
    return 0;
}
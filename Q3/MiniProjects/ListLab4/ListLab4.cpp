#include <iostream>
#include "ListLab4.h"
using namespace std;

int main() {
    ListNode* head = new ListNode("hello", NULL);
    head->add(new ListNode("foo", head));
    head->add(new ListNode("boo", head));
    head->add(new ListNode("nonsense", head));
    cout << head;
    head->printForward();
    head->printForward(5);
    head->printBackward();
    head->printBackward(5);
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
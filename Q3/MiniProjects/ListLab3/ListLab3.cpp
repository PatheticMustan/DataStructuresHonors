#include <iostream>
#include "ListLab3.h"
using namespace std;

int main() {
    ListNode* head = new ListNode("hello", NULL);
    head = new ListNode("foo", head);
    head = head->add(new ListNode("boo", head));
    head = head->add(new ListNode("nonsense", head));
    head = new ListNode("computer", new ListNode("science", new ListNode("c++", new ListNode("coffee", head))));
    cout << head;

    head = head->add(new ListNode("nat", NULL), 3);
    cout << head;

    head = head->remove();
    cout << head;
    head = head->remove(0);
    cout << head;
    head = head->remove(1);
    cout << head;
    head = head->remove(4);
    cout << head;
    head = head->remove(4);
    cout << head;

    return 0;
}
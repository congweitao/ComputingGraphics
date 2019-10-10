#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode* head(int v):val(v),next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
	ListNode* newnode = NULL;
	while (head) {
             ListNode* t = head->next;
	     head->next = newhead;
	     newhead = head;
	     head = t;
	}
	return newnode;
}



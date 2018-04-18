#include "Solution.h"

int Solution::remove_duplicates(vector<int>& nums) {
    // remove duplicates in an array
    int i = 0, count = nums.size()-1;

    while (count)
    {
	if (nums[i] == nums[i+1])
	{ 
	    nums.erase(nums.begin()+ i + 1);
	    count--;
	}
	else {
	    i++;
	    count--;
	}
    }

    return (i+1);
}

ListNode *create_cycle_linkedlist(int n, int m) {
    ListNode *head, *p, *q, *temp;
    head = new ListNode;
    p = head;
    int i = 1;
    while (i < n) {
        if (i <= m) {
            q = new ListNode;
            q->val = i++;
            p->next = q;
            p = q;
            temp = p;
        }
        else {
            q = new ListNode;
            q->val = i++;
            q->next = temp;
            p->next = q;
            p = q;
        }
    }
    return head->next;
}

ListNode *create_nocycle_linkedlist(int n) {
    ListNode *head, *p, *q;
    head = new ListNode;
    p = head;
    int i = 1;
    while (i < n) {
	p->val = i++;
	q = new ListNode;
	p->next = q;
	p = q;
    }
    p->next = NULL;
    return head;
}

bool Solution::has_cycle(ListNode* head) {
    // cycle linked list
    ListNode *pf = head;
    ListNode *ps = head;

    while (pf != NULL && pf->next != NULL) {
	pf = pf->next->next;
	ps = ps->next;
	if (pf == ps)
	    return true;
    }
    return false;    
}

string Solution::reverse_string(string s) {
    int len = s.size();
    char tmp;
    int i = 0, j = len - 1;
    while ((i <= len/2)&&(j>=len/2)) { 
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
	i++;
	j--;
    }
    return s;
}

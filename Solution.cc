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

BinaryTree* BinaryTree::create_tree() {
    BinaryTree* g = new BinaryTree(1);
    BinaryTree* e = new BinaryTree(2);
    BinaryTree* f = new BinaryTree(3);
    BinaryTree* d = new BinaryTree(4,NULL,g);
    BinaryTree* c = new BinaryTree(5,NULL,f);
    BinaryTree* b = new BinaryTree(6,d,e);
    BinaryTree* a = new BinaryTree(7,b,c);

    return a;
}

int BinaryTree::max_depth(BinaryTree* root) {
    if (root == NULL)
	return 0;
    int ldepth = max_depth(root->left);
    int rdepth = max_depth(root->right);
    int depth = 1 + (ldepth>rdepth?ldepth:rdepth);

    return depth;
}

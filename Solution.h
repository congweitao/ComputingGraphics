#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>
#include <map>
#include <stack> 
#include <unordered_map>
#include <math.h>
#include <stdlib.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};

ListNode *create_cycle_linkedlist(int n, int m);
ListNode *create_nocycle_linkedlist(int n);

class Solution {
public:
    vector<int> two_sum(vector<int>& nums, int target);
    int remove_duplicates(vector<int>& nums);
    bool has_cycle(ListNode *head);
    string reverse_string(string s);

    void display(ListNode* head);
    ListNode* reverse_list(ListNode* head) {
        if (head == NULL)
	    return head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur != NULL) {
            prev->next = cur->next;
            cur->next = head;
            head = cur;
            cur = prev->next;
	}
        return head;
    }
    
    ListNode* remove_nth_node(ListNode* head, int n) {
	ListNode* pre = head;
	ListNode* cur = head->next;
	for (int i = 0; i < n; i++) cur = cur->next;
	if (cur == NULL) return head->next;
	while (cur->next != NULL) {
	    cur = cur->next;
	    pre = pre->next;
	}
	pre->next = pre->next->next;
	return head;
    }
    
    ListNode* add_two_sum(ListNode* l1, ListNode* l2) {
	ListNode* res = new ListNode(-1);
	ListNode* cur = res;

	int carry = 0;
	while (l1 || l2) {
	    int n1 = l1 ? l1->val : 0;
	    int n2 = l2 ? l2->val : 0;
	    int sum = n1 + n2 + carry;
	    carry = sum / 10;
	    cur->next = new ListNode(sum%10);
	    if (l1) l1 = l1->next;
	    if (l2) l2 = l2->next;
	}
	if (carry) cur->next = new ListNode(1);
	return res->next;
    }

    bool is_valid_parentheses(string s) {
	stack<char> parentheses;
	for (int i = 0; i < s.size(); i++) {
	    if (s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
	    else {
		if (parentheses.empty()) return false;
                if (s[i] == ')' && parentheses.top() != '(') return false;
                if (s[i] == ']' && parentheses.top() != '[') return false;
                if (s[i] == '}' && parentheses.top() != '{') return false;
                parentheses.pop();
		return true;
	    }
	}
	return false;
    }
};

class LRUCache {
public:
    LRUCache* prev;
    LRUCache* next;
    int value;
    int key;
public:
    LRUCache(int capacity);
    int get(int key);
    int set(int key, int value);
};

class BTree {
public:
    
};

class BinaryTree {
public:
    int val;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree():val(0),left(NULL),right(NULL) {}
    BinaryTree(int x,BinaryTree* L=NULL, BinaryTree* R=NULL):val(x),left(L),right(R) {}
    BinaryTree* create_tree();
    int max_depth(BinaryTree* root); 
    bool symetric_tree(BinaryTree* L, BinaryTree* R);
    bool is_symetric(BinaryTree* root);
    bool valid_tree(BinaryTree* root);
};

#endif

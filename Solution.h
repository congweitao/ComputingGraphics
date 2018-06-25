#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>
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

#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

ListNode *create_cycle_linkedlist(int n, int m);
ListNode *create_nocycle_linkedlist(int n);

class Solution {
public:
    int remove_duplicates(vector<int>& nums);
    bool has_cycle(ListNode *head);
    string reverse_string(string s);
};

#endif

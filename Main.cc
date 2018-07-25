#include <iostream>
#include <vector>
#include <list>

#include "Solution.h"

using namespace std;

class Solution sl;
class BinaryTree bt;


int main() {
//-----------------------------------------------------
/*  int len;
    vector<int> data = {1, 1, 2, 2, 3, 3, 3, 4, 4};
    for (int i = 0; i < data.size(); i++) {
	cout << data[i] << " ";
    }
    cout << endl;

    len = sl.remove_duplicates(data);

    for (int i = 0; i < len; i++) {
	cout << data[i] << " ";
    }
    cout << endl; */
//---------------------------------------------------
/*  ListNode *ln1, *ln2;
    ln1 = create_cycle_linkedlist(10,6);
    ln2 = create_nocycle_linkedlist(10);
    if (sl.has_cycle(ln2)) {
	cout << "There is cycle in ln2" << endl;
    }
    else {
	cout << "There is no cycle of ln2" << endl;
    } */
//-------------------------------------------------
//    BinaryTree* root = bt.create_tree();
    /* int dpt = 0;
    dpt = bt.max_depth(root);
    cout << dpt << endl; */
//   if (!bt.is_symetric(root))
//	cout << "Is not a symetric binary tree." << endl;
/*    if (bt.valid_tree(root))
	cout << "Valid BinaryTree." << endl;
    else
	cout << "Invalid BinaryTree." << endl; */

//--------------------------------------------------
/*    string s1 = "Hello World!";
    string s2 = "";
    s2= sl.reverse_string(s1);
    cout << s2 << endl; */

    /* ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for (int i = 0; i < 10; i++)
    {
        ListNode* newnode = new ListNode(floor(rand()%100));
        cur->next = newnode;
        cur = newnode;
    }
    sl.display(head);
    //head = sl.reverse_list(head);
    head = sl.remove_nth_node(head,5);
    sl.display(head); */

    /*  // two sum problem
    vector<int> n = {4,5,7,9,11};
    int t = 12;
    vector<int> s;

    s = sl.two_sum(n,t);
    vector<int>::iterator it;
    it = s.begin();
    while (it != s.end()) {
	cout << "s : " << *it << endl;
	it++;
    } */
    /* is valid parentheses */
    /* string s = "{dadaddaddada}";
    if (sl.is_valid_parentheses(s)) 
	cout << "valid." << endl; */

    /** merge two listnode */
    ListNode *l1, *l2;
    ListNode* l3 = NULL;
    l1 = create_nocycle_linkedlist(3);
    sl.display(l1);
    l2 = create_nocycle_linkedlist(4);
    sl.display(l2);
    l3 = sl.merge_twolistnode(l1,l2);
    sl.display(l3);
}

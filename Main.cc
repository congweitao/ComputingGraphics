#include <iostream>
#include <vector>

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
    BinaryTree* root = bt.create_tree();
    int dpt = 0;
    dpt = bt.max_depth(root);
    cout << dpt << endl; 
    if (bt.valid_tree(root))
	cout << "Valid BinaryTree." << endl;
    else
	cout << "Invalid BinaryTree." << endl;

//--------------------------------------------------
/*    string s1 = "Hello World!";
    string s2 = "";
    s2= sl.reverse_string(s1);
    cout << s2 << endl; */
}

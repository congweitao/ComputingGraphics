#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

class Solution sl;

int main() {
    int len;
    vector<int> data = {1, 1, 2, 2, 3, 3, 3, 4, 4};
    for (int i = 0; i < data.size(); i++) {
	cout << data[i] << " ";
    }
    cout << endl;

    len = sl.remove_duplicates(data);

    for (int i = 0; i < len; i++) {
	cout << data[i] << " ";
    }
    cout << endl;
}

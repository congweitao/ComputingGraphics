#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
	vector<int> m(128,-1);
	int res = 0, left = -1;
	for (int i = 0; i < s.size(); i++) {
		left = max(left, m[s[i]]);
		m[s[i]] = i;
		res = max(res, i - left);
	}
	return res;
}

int main() {
	string str = "pwwkeabdecfwdsd";
	cout << "the length of the longest substring without repeating characters is :" << lengthOfLongestSubstring(str) << endl;
	return 0;
}


#include <iostream>
#include <string>

using namespace std;

int main() {
    // string s = "abcdefghijklmnopqsrtuvwxyzzyxwvutrsqponmlkjihgfedcba";
    string s = "idadaddadadaniabcdefghijklmnopqsrtuvwxyzzyxwvutrsqponmlkjihgfedcbarrrrrrrrr";

    cout << " length of string s is " << s.size() << endl;

    int dp[s.size()][s.size()];
    int maxlen = 1; // save the max length of palindromic substring
    int start; // start index of Palindromic substring

    for (int i = 0; i < s.size(); i++)
	for (int j = 0; j <= i; j++) {
	    if ((i - j) < 2)
		dp[j][i] = (s[i]==s[j]) ? 1:0;
	    else {
		dp[j][i] = ((s[i]==s[j]) && (dp[j+1][i-1])) ? 1:0;
	    }
	    if (dp[j][i] && maxlen < i - j + 1) {
		maxlen = i - j + 1;
		start = j;	
	    }    		
	}
    cout << "max length is " << maxlen << ":" << s.substr(start,maxlen) << endl; 
}   

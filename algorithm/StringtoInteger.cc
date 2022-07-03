#include <iostream>

using namespace std;

int myatoi(string s) {
    int i = 0, len = s.size();
    int sign = 1;
    int res = 0;
    while (i < len && s[i] == ' ') i++;
    if (s[i] == '-') { sign = -1; i++;}
    if (s[i] == '+') {sign = 1; i++;}
    while (i < len && s[i] >= '0' && s[i] <= '9') {
	if (res > INT_MAX/10 || (res == INT_MAX/10 && s[i] - '0' > '7'))
	    return (sign == 0)?INT_MAX:INT_MIN;
	res = res*10 + (s[i++] - '0');
    }
    return res*sign; 
}

int main() {
    string s;
    cout << "The string is : " << endl;
    cin>>s;

    cout << " string to ineteger is : " << myatoi(s) << endl;    
}

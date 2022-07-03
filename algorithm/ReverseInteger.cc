#include <iostream>

using namespace std;

int main() {
    int x;
    int res;
    cout << "Please input the integer : ";
    cin >> x;
    
    while (x) {
	if (abs(res) > INT_MAX / 10) { res = 0; break;}
	res = res*10 + x%10;
	x = x/10;
    }
    cout << "max integer is : " << INT_MAX << endl;
    cout << "reversed integer is : " << res << endl;
}

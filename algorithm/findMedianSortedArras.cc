#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
    int m = num1.size();
    int n = num2.size();
    if (m == 0)
	return (n%2==0) ? (num2[n/2] + num2[n/2-1])/2 : num2[n/2];
    if (n == 0)
	return (m%2==0) ? (num1[m/2] + num1[m/2-1])/2 : num1[m/2];
    if (num1[m-1] <= num2[0]) {
	if ((m+n)%2 == 0) { 
	    if ((m+n)/2 <= (m-1))
		return (num1[(m+n)/2] + num1[(m+n)/2 - 1]) / 2;
	    else
		return (num2[(m+n)/2 - m ] + num2[(m+n)/2 - 1 - m]) / 2;
	}
	else {
	    if ((m+n)/2 <= (m-1))
		return num1[(m+n)/2];
	    else
		return num2[(m+n)/2 - m];
	}
    }
    if (num1[0] > num2[n-1]) {
	if ((m+n)%2 == 0) { 
	    if ((m+n)/2 <= (n-1))
		return (num2[(m+n)/2] + num2[(m+n)/2 - 1]) / 2;
	    else
		return (num1[(m+n)/2 - n ] + num1[(m+n)/2 - 1 - n]) / 2;
	}
	else {
	    if ((m+n)/2 <= (n-1))
		return num2[(m+n)/2];
	    else
		return num1[(m+n)/2 - n];
	}
    }
    
    return 0;
}

int main() {
	int A[7] = {8,9,10,11,12,13,14};
	int B[4] = {1,2,3,4};
	vector<int> a(A,A+7);
	vector<int> b(B,B+4);
	cout << "the median of the two sorted arrays is : " 
		<< findMedianSortedArrays(a,b)
		<< endl;
	return 0;
}

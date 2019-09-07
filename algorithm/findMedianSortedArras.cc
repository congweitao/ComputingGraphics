#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
	
}

int main() {
	int A[7] = {1,2,3,4,5,6,7};
	int B[10] = {3,4,5,6,7,7,8,9,10,11};
	vector<int> a(A,A+7);
	vector<int> b(B,B+10);
	cout << "the median of the two sorted arrays is : " 
		<< findMedianSortedArrays(a,b)
		<< endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
	int m = num1.size();
	int n = num2.size();
	int min_index = 0, max_index = m, i, j;
	double median;
	while (min_index <= max_index) {
		i = (min_index + max_index) / 2;
		j = ((m + n +1) / 2) - i;
		
		// check if num1 or num2 is empty in the halt partition
		// searching on the right
		if ( i < m && j > 0 && num2[j -1] > num1[i]) 
			min_index = i + 1;
		// searching on the left
		else if (i > 0 && j < n && num2[j] < num1[i - 1])
			max_index = i - 1;
		else {
			if (i==0)
				median = num2[j - 1];
			else if (j == 0)
				median = num1[j - 1];
			else
				median = max(num1[i - 1], num2[j -1]);
			break;
		}
	}
	if ((n + m) % 2 == 1) 
		return median;
	if (i == m)
		return (median + num2[j]) / 2;
	if (j == n)
		return (median + num1[i]) / 2;
	return (median + min(num1[i],num2[j])) / 2;
}

int main() {
	int A[7] = {8,9,10,11,12,13,14};
	int B[12] = {1,2,3,4,21,22,23,24,25,26,27,34};
	vector<int> a(A,A+7);
	vector<int> b(B,B+12);
	cout << "the median of the two sorted arrays is : " 
		<< findMedianSortedArrays(a,b)
		<< endl;
	return 0;
}

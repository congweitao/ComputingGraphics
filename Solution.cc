#include "Solution.h"

int Solution::remove_duplicates(vector<int>& nums) {
    // remove duplicates in an array
    int i = 0, count = nums.size()-1;

    while (count)
    {
	if (nums[i] == nums[i+1])
	{ 
	    nums.erase(nums.begin()+ i + 1);
	    count--;
	}
	else {
	    i++;
	    count--;
	}
    }

    return (i+1);
}

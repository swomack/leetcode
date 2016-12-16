#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	vector<int> stored;
	vector<int> permute;

	long long int call_possible;
	long long int saved_call;

	Solution(vector<int> nums) 
	{
		stored = nums;
		permute = nums;

		call_possible = 1;

		for (long long int i = 2; i <= nums.size(); i++)
			call_possible *= i;

		saved_call = call_possible;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() 
	{
		return stored;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() 
	{
		call_possible--;

		if (call_possible < 0)
		{
			permute = stored;
			call_possible = saved_call;
		}
			

		next_permutation(permute.begin(), permute.end());

		return permute;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/

int main()
{
	vector<int> param{ 1,2,3 };
	Solution s(param);
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	vector<int> stored;
	vector<int> permuted;

	Solution(vector<int> nums) 
	{
		stored = nums;
		permuted = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() 
	{
		return stored;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() 
	{
		// fisher-yates 
	
		for (int i = permuted.size() - 1; i >= 0; i--)
		{
			int rand_index = rand() % (i + 1);

			swap(&permuted[i], &permuted[rand_index]);
		}

		return permuted;
	}

	void swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
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
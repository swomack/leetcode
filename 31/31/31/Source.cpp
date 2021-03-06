#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	int find_replace_index(vector<int>& nums)
	{
		int index = -1;

		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] < nums[i + 1])
				return i;
		}

		return index;
	}

	int find_swap_index(vector<int>& nums, int k)
	{
		int swap_index = -1;
		for (int i = nums.size() - 1; i > k; i--)
		{
			if (nums[i] > nums[k])
			{
				swap_index = i;
				break;
			}
		}

		return swap_index;
	}

	void swap(int* a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void nextPermutation(vector<int>& nums) 
	{
		if (nums.size() <= 1)
			return;

		int replace_index = find_replace_index(nums);
		if (replace_index < 0)
		{
			reverse(nums.begin(), nums.end());
			return;
		}
			

		int swap_index = find_swap_index(nums, replace_index);

		swap(&nums[replace_index], &nums[swap_index]);

		reverse(nums.begin() + replace_index + 1, nums.end());
	}
};

int main()
{
	vector<int> param{ 1,2 };
	Solution s;

	s.nextPermutation(param);

	return 0;
}
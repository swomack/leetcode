#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution 
{
public:

	void swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	int partition(vector<int>& nums, int i, int j, int pivot_index)
	{
		swap(&nums[j], &nums[pivot_index]);

		int start = i;

		for (; i < j; i++)
		{
			if (nums[i] < nums[j])
			{
				swap(&nums[start], &nums[i]);
				start++;
			}
		}

		swap(&nums[start], &nums[j]);

		return start;
	}

	int quickSelect(vector<int>& nums, int i, int j, int k)
	{
		if (i == j)
			return nums[i];

		int pivot_index = i + floor(rand() % (j - i + 1));
		pivot_index = partition(nums, i, j, pivot_index);

		if (pivot_index == k)
			return nums[pivot_index];

		if (pivot_index < k)
			return quickSelect(nums, pivot_index + 1, j, k);

		return quickSelect(nums, i, pivot_index - 1, k);
	}

	int minMoves2(vector<int>& nums) 
	{
		int median = quickSelect(nums, 0, nums.size() - 1, nums.size() / 2);
		int count = 0;
		for_each(nums.begin(), nums.end(), [&count, &median](int element) {
			count += abs(element - median);
		});

		return count;
	}
};

int main()
{
	Solution s;
	return 0;
}
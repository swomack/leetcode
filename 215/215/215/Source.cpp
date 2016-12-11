#include <iostream>
#include <vector>
#include <algorithm>

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

	int partition(vector<int>& nums, int i, int j)
	{
		int lower = i - 1;

		for (; i < j; i++)
		{
			if (nums[i] > nums[j])
			{
				lower++;
				swap(&nums[lower], &nums[i]);
			}
		}

		lower++;
		swap(&nums[lower], &nums[j]);

		return lower;
	}

	void findKthLargestQuickSort(vector<int>& nums, int i, int j, int k)
	{
		int pivot_pos = partition(nums, i, j);

		if (pivot_pos == k)
			return;

		if (k < pivot_pos)
			findKthLargestQuickSort(nums, i, pivot_pos - 1, k);
		else
			findKthLargestQuickSort(nums, pivot_pos + 1, j, k);
	}

	int findKthLargest(vector<int>& nums, int k) 
	{
		findKthLargestQuickSort(nums, 0, nums.size() - 1, --k);

		return nums[k];
	}
};

int main()
{
	Solution s;
	vector<int> param{ 2,1,3 };
	int largest = s.findKthLargest(param, 2);
	return 0;
}
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

	int partition(vector<int>& nums, int i, int j, int pivot_index)
	{
		swap(&nums[j], &nums[pivot_index]);
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

	int findKthLargestQuickSort(vector<int>& nums, int i, int j, int k)
	{
		if (i == j)
			return nums[i];

		int pivot_index = i + floor(rand() % (j - i + 1));
		pivot_index = partition(nums, i, j, pivot_index);

		if (pivot_index == k)
			return nums[pivot_index];

		if (k < pivot_index)
			return findKthLargestQuickSort(nums, i, pivot_index - 1, k);
		else
			return findKthLargestQuickSort(nums, pivot_index + 1, j, k);
	}

	int findKthLargest(vector<int>& nums, int k) 
	{
		return findKthLargestQuickSort(nums, 0, nums.size() - 1, --k);
	}
};

int main()
{
	Solution s;
	vector<int> param{ 2,1,3 };
	int largest = s.findKthLargest(param, 2);
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	void swap(int *a, int *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	int removeDuplicates(vector<int>& nums) 
	{
		if (nums.size() < 3)
			return nums.size();

		int head = 2, tail = 1;

		for (; head < nums.size(); head++)
		{
			if (nums[head] == nums[tail] && nums[head] == nums[tail - 1])
				continue;

			swap(&nums[++tail], &nums[head]);
		}

		return ++tail;
	}
};

int main()
{
	Solution s;
	return 0;
}
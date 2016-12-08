#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

	void swap(int* a, int* b)
	{
		if (*a == *b)
			return;
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}

	int removeDuplicates(vector<int>& nums)
	{
		int length = nums.size();
		if (length < 2)
			return length;

		int head = 0;
		int tail = 0;

		while (head < length)
		{
			if (nums[head] == nums[tail])
			{
				head++;
				continue;
			}

			swap(&nums[head++], &nums[++tail]);
		}

		return ++tail;
	}
};

int main()
{
	Solution s;
	vector<int> v{ 1, 2, 3 };
	int length = s.removeDuplicates(v);
	return 0;
}
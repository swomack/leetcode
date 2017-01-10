#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	void swap(int* a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void sortColors(vector<int>& nums) 
	{
		int i = 0;

		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] == 0)
			{
				swap(&nums[i], &nums[j]);
				i++;
			}
		}

		for (int j = i; j < nums.size(); j++)
		{
			if (nums[j] == 1)
			{
				swap(&nums[i], &nums[j]);
				i++;
			}
		}
	}
};

int main()
{
	Solution s;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int zero_copied = 0;

		for (int i = 0; i < nums.size() - zero_copied; i++)
		{
			if (nums[i] != 0)
				continue;
			int range = nums.size() - zero_copied;
			for (int j = i + 1; j < range; j++)
			{
				int temp = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = temp;
			}

			zero_copied++;
			i--;
		}
	}
};

int main()
{
	Solution s;
	vector<int> param{0, 0, 1};
	s.moveZeroes(param);

	getchar();
}
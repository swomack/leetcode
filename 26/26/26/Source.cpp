#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int removeDuplicates(vector<int>& nums) 
	{
		int length = nums.size();
		int k = length;

		for (int i = 0; i < k - 1; i++)
		{
			if (nums[i] == nums[i + 1])
				length--;
		}

		return length;
	}
};

int main()
{
	Solution s;
	vector<int> v{ };
	int length = s.removeDuplicates(v);
	return 0;
}
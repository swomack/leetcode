#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int findDuplicate(vector<int>& nums) 
	{
		//floyd cycle detection
		int n = nums.size();
		int slow = n;
		int fast = n;

		while (true)
		{
			slow = nums[slow - 1];
			fast = nums[nums[fast - 1] - 1];

			if (slow == fast)
				break;
		}

		int finder = n;

		while (true)
		{
			finder = nums[finder - 1];
			slow = nums[slow - 1];

			if (slow == finder)
				break;
		}
		return slow;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 1,1,2 };
	int k = s.findDuplicate(param);
	return 0;
}
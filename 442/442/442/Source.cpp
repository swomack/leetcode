#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<int> findDuplicates(vector<int>& nums) 
	{
		int length = nums.size();
		vector<int> res;
		
		for (int i = 0; i < length; i++)
		{
			int index = abs(nums[i]) - 1;

			if (nums[index] < 0) // already encountered
				res.push_back(abs(nums[i]));
			else         // mark that it has been encountered
				nums[index] *= -1;

		}

		return res;
	}
};

int main()
{
	Solution s;
	return 0;
}
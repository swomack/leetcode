#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<int> findDuplicates(vector<int>& nums) 
	{
		int length = nums.size();
		vector<int> map(length);
		for (int i = 0; i < length; i++)
			map[nums[i] - 1] ++;

		vector<int> res;

		for (int i = 0; i < length; i++)
		{
			if (map[i] == 2)
				res.push_back(i + 1);
		}

		return res;
	}
};

int main()
{
	Solution s;
	return 0;
}
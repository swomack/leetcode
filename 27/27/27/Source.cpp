#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int removeElement(vector<int>& nums, int val) 
	{
		int valid = -1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				valid++;
				nums[valid] = nums[i];
			}
		}

		return valid + 1;
	}
};

int main()
{
	Solution s;
	return 0;
}
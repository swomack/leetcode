#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	void swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	vector<int> findDisappearedNumbers(vector<int>& nums) 
	{
		vector<int> res;

		for (int i = 0; i < nums.size(); i++)
		{
			while (true)
			{
				if (nums[i] == nums[nums[i] - 1])
					break;
				swap(&nums[i], &nums[nums[i] - 1]);
			}
				
		}

	
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1)
				res.push_back(i + 1);
		}

		return res;

	}
};

int main()
{
	Solution s;
	vector<int> param{ 4,3,2,7,8,2,3,1 };
	vector<int> res = s.findDisappearedNumbers(param);
	return 0;
}
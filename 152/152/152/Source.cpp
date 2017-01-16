#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution 
{
public:
	int maxProduct(vector<int>& nums) 
	{
		int max_prod = nums[0];
		if (nums.size() <= 1)
			return max_prod;

		vector<int> max_pos(nums.size());
		vector<int> max_neg(nums.size());

		max_pos[0] = nums[0] > 0 ? nums[0] : INT_MIN;
		max_neg[0] = nums[0];


		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > 0)
			{
				if (max_pos[i - 1] == INT_MIN)
				{
					max_pos[i] = nums[i];
				}
				else
				{
					max_pos[i] = max_pos[i - 1] * nums[i];
				}
				
				
				if (max_neg[i - 1] == INT_MAX)
				{
					max_neg[i] = nums[i];
				}
				else
				{
					max_neg[i] = max_neg[i - 1] * nums[i];
				}
			}
			else if (nums[i] < 0)
			{
				if (max_neg[i - 1] == INT_MAX)
				{
					max_neg[i] = nums[i];
				}
				else if(max_neg[i - 1] < 0)
				{
					max_pos[i] = max_neg[i - 1] * nums[i];
					max_neg[i] = nums[i];
				}
				else
				{
					max_neg[i] = max_neg[i - 1] * nums[i];
					max_pos[i] = INT_MIN;
				}
			}
			else
			{
				max_pos[i] = INT_MIN;
				max_neg[i] = INT_MAX;
			}
		}

		max_prod = INT_MIN;

		for (int i = 0; i < max_pos.size(); i++)
			max_prod = max(max_prod, max_pos[i]);

		for (int i = 0; i < max_neg.size(); i++)
		{
			if(max_neg[i] != INT_MAX)
				max_prod = max(max_prod, max_neg[i]);
		}
			

		return max_prod;
	}
};

int main()
{
	Solution s;
	vector<int> param{ -1,-2,-9,-6 };
	int res = s.maxProduct(param);
	return 0;
}
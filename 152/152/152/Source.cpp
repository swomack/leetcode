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
		
		for (int i = 1, r_max = max_prod, r_min = max_prod; i < nums.size(); i++)
		{
			if (nums[i] >= 0)
			{
				r_max = max(r_max * nums[i], nums[i]);
				r_min = min(r_min * nums[i], nums[i]);
			}
			else
			{
				int ma = r_max;
				
				r_max = max(r_min * nums[i], nums[i]);
				r_min = min(ma * nums[i], nums[i]);
			}


			max_prod = max(max_prod, r_max);
			max_prod = max(max_prod, r_min);
		}

		return max_prod;
	}
};

int main()
{
	Solution s;
	//vector<int> param{ -1,-2,-9,-6 };
	vector<int> param{ 2,-5,-2, -4, 3 };
	int res = s.maxProduct(param);
	return 0;
}
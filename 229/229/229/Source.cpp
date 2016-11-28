#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution 
{
public:

	vector<int> majorityElement(vector<int>& nums) 
	{

		vector<int> result;

		if (nums.size() <= 0)
			return result;

		int major_1 = -1;
		int major_count_1 = 0;
		int major_2 = -1;
		int major_count_2 = 0;
		
		for (int i = 0; i < nums.size(); i++)
		{
			if (major_1 == nums[i])
			{
				major_count_1++;
			}
			else if (major_2 == nums[i])
			{
				major_count_2 ++;
			}
			else if (major_count_1 == 0)
			{
				major_1 = nums[i];
				major_count_1 = 1;
			}
			else if (major_count_2 == 0)
			{
				major_2 = nums[i];
				major_count_2 = 1;
			}
			else
			{
				major_count_1--;
				major_count_2--;
			}
		}

		vector<int> freq(2);

		for (int i = 0; i < nums.size(); i++)
		{
			if (major_1 == nums[i])
				freq[0]++;
			else if (major_2 == nums[i])
				freq[1]++;
		}

		int min_size = nums.size() / 3;
		if (freq[0] > min_size)
			result.push_back(major_1);
		if (freq[1] > min_size)
			result.push_back(major_2);
		
		return result;
	}
};

int main()
{
	Solution s;

	vector<int> param{1, 2, 2, 3, 2, 1, 1, 3};

	vector<int> result = s.majorityElement(param);

	getchar();

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution 
{
public:

	bool majortyElementHelper(vector<int>& nums, int min_count, int &val)
	{
		int major = 0;
		int count = 0;
		int index = -1;

		bool ret = true;

		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0)
			{
				count = 1;
				major = nums[i];
				index = i;
			}
			else
			{
				if (major == nums[i])
					count++;
				else
					count--;
			}
		}


		if (min_count >= 0)
		{
			int count_major = 0;

			for (int i = 0; i < nums.size(); i++)
			{
				if (major == nums[i])
				{
					count_major++;
				}
			}

			if (count_major < min_count)
				ret = false;
		}
		

		nums.erase(std::remove(nums.begin(), nums.end(), major), nums.end());

		val = major;

		return ret;
	}

	vector<int> majorityElement(vector<int>& nums) 
	{

		vector<int> result;

		if (nums.size() <= 0)
			return result;

		int min_size = nums.size() / 3 + 1;
		int r;
		if(majortyElementHelper(nums, min_size, r))
			result.push_back(r);

		if(majortyElementHelper(nums, min_size, r))
			result.push_back(r);
		
		return result;
	}
};

int main()
{
	Solution s;

	vector<int> param{1, 1,1, 2, 3, 4, 5, 6};

	vector<int> result = s.majorityElement(param);

	getchar();

	return 0;
}
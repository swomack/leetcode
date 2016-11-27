#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution 
{
public:
	int majorityElement(vector<int>& nums) 
	{
		// Moore's majority voting algorithm
		/*int major = nums[0];
		int major_count = 1;

		for_each(nums.begin() + 1, nums.end(), [&major, &major_count](int element) {
			if (major == element)
				major_count++;
			else
				major_count--;

			if (major_count == 0)
			{
				major = element;
				major_count = 1;
			}
			
		});

		return major;*/

		// bit manioulation solution
		bitset<32> major;
		vector<int> bit_value(32);

		for (int i = 0; i < nums.size(); i++)
		{
			bitset<32> bits(nums[i]);

			for (int i = 0; i < 32; i++)
			{
				if (bits[i])
					bit_value[i] ++;
			}
		}

		int size = nums.size() / 2;

		for (int i = 0; i < 32; i++)
		{
			if (bit_value[i] > size)
				major[i] = 1;
		}

		return major.to_ulong();

	}
};

int main()
{
	Solution s;
	vector<int> param{ 1 };
	int res = s.majorityElement(param);
	getchar();
	return 0;
}
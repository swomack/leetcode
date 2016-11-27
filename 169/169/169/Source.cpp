#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int majorityElement(vector<int>& nums) 
	{
		int major = nums[0];
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

		return major;
	}
};

int main()
{
	return 0;
}
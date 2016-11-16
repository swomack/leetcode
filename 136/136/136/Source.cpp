#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int singleNumber(vector<int>& nums) 
	{
		if (nums.size() == 1)
			return nums[0];

		// xor is commutative, so A ^ B ^ C ^ A ^ B = C
		int result = nums[0];

		for_each(nums.begin() + 1, nums.end(), [&result](int element) {
			result ^= element;
		});

		return result;
	}
};
int main()
{
	Solution s;

	vector<int> params;
	params.push_back(1);
	params.push_back(2);
	params.push_back(3);
	params.push_back(4);
	params.push_back(3);
	params.push_back(2);
	params.push_back(1);

	int result = s.singleNumber(params);

	getchar();
}
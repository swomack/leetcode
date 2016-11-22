#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	// 3 ^ 0 ^ 0 ^ 1 ^ 1 ^ 3 ^ 2 = 2 
	int missingNumber(vector<int>& nums) 
	{
		int result = nums.size();

		int index = 0;

		for_each(nums.begin(), nums.end(), [&result, &index](int element) {
			result ^= element;
			result ^= index++;
		});


		return result;

	}
};

int main()
{
	Solution s;

	vector<int> param{ 0, 1, 3 };

	int res = s.missingNumber(param);

	getchar();
	return 0;
}
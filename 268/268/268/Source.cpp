#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int missingNumber(vector<int>& nums) 
	{
		int size = nums.size();

		int expected_sum = ((size) * (size + 1)) / 2;

		int sum = 0;

		for_each(nums.begin(), nums.end(), [&sum](int element) {
			sum += element;
		});


		return expected_sum - sum;

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
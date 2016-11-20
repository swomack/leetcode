#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution 
{
public:
	int minMoves(vector<int>& nums) 
	{
		int result = 0;
		int min_element = INT_MAX;

		for_each(nums.begin(), nums.end(), [&min_element](int element) {
			min_element = min(min_element, element);
		});

		
		for_each(nums.begin(), nums.end(), [&min_element, &result](int element) {
			result += (element - min_element);
		});

		return result;
	}
};

int main()
{
	Solution s;

	vector<int> param{ 1, 2, 5 };


	int result = s.minMoves(param);

	getchar();
}
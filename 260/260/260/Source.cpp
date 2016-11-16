#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution 
{
public:
	vector<int> singleNumber(vector<int>& nums) 
	{
		vector<int> result;
		
		int xoor = 0;

		for_each(nums.begin(), nums.end(), [&xoor](int element) {
			xoor ^= element;
		});

		// find out the different bit
		int mask = 1;

		while (!(xoor & mask))
			mask <<= 1;

		// divide the numbers in two groups, in first group where the mask bit is set, on the second the mask bit is not set
		// since num1 and num2 got different bit at that mask bit, the two group will contain two numbers. Morover the other members
		// of the group will be in twin
		int first = 0;
		int second = 0;

		for_each(nums.begin(), nums.end(), [&mask, &first, &second](int element) {
			if (element & mask)
				first ^= element;
			else
				second ^= element;
		});


		result.push_back(first);
		result.push_back(second);

		return result;

	}
};


int main()
{
	Solution s;

	vector<int> param;
	param.push_back(1);
	param.push_back(2);
	param.push_back(3);
	param.push_back(5);
	param.push_back(2);
	param.push_back(1);

	vector<int> result = s.singleNumber(param);

	getchar();
}
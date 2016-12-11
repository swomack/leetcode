#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int thirdMax(vector<int>& nums) 
	{
		pair<int, bool> max1;
		pair<int, bool> max2;
		pair<int, bool> max3;

		for_each(nums.begin(), nums.end(), [&max1, &max2, &max3](int element) {
			if (max1.second == false)
			{
				max1.first = element;
				max1.second = true;
				return;
			}

			if (max1.first == element)
				return;

			if (max1.first < element)
			{
				int temp = max1.first;
				max1.first = element;

				if (max2.second == false)
				{
					max2.first = temp;
					max2.second = true;
					return;
				}

				
				int temp2 = max2.first;
				max2.first = temp;

				max3.first = temp2;
				max3.second = true;
				return;
			}

			if (max2.second == false)
			{
				max2.first = element;
				max2.second = true;
				return;
			}

			if (max2.first == element)
				return;

			if (max2.first < element)
			{
				int temp = max2.first;
				max2.first = element;

				max3.first = temp;
				max3.second = true;

				return;
			}

			if (max3.second == false)
			{
				max3.first = element;
				max3.second = true;
				return;
			}

			if (max3.first < element)
			{
				
				max3.first = element;
			}
		});

		return max3.second ? max3.first : max1.first;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 1,2,2,3,3 };
	int res = s.thirdMax(param);
	return 0;
}
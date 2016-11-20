#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

	// swap the zeros with the next element if the element is not 0
	// if the element is zero then just go through
	// swap with the first zero of the zero sequence and increment the first_zero value so that 
	// first zero always point to the first element of the zero sequence

	void moveZeroes(vector<int>& nums)
	{
		int first_zero_element = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0 && first_zero_element == -1) {
				first_zero_element = i;
				continue;
			}
			else if (nums[i] == 0)
			{
				continue;
			}
			else if (nums[i] && first_zero_element == -1)
			{
				continue;
			}

			nums[first_zero_element] = nums[i];
			nums[i] = 0;
			first_zero_element++;
		}
	}
};

int main()
{
	Solution s;
	vector<int> param{0, 0, 1};
	s.moveZeroes(param);

	getchar();
}
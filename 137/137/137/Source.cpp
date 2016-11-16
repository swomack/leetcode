#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int singleNumber(vector<int>& nums) 
	{
		int once_one_bit = 0;
		int twice_one_bit = 0;
		int thrice_one_bit = 0;


		for_each(nums.begin(), nums.end(), [&once_one_bit, &twice_one_bit, &thrice_one_bit](int element) {
			
			// we keep track of the bits which has been 1 twice already
			twice_one_bit |= (once_one_bit & element);

			// We also keep track of the bits which has been 1 once
			once_one_bit ^= element;

			// we calculate those bits which been 1 twice and then 1 again after that
			thrice_one_bit = (twice_one_bit & once_one_bit);

			// we reset those bits which has been 1 three times
			twice_one_bit &= (~thrice_one_bit);
			once_one_bit &= (~thrice_one_bit);
		});


		return once_one_bit;
	}
};

int main()
{
	Solution s;
	vector<int> param;
	param.push_back(1);
	param.push_back(2);
	param.push_back(3);
	param.push_back(4);
	param.push_back(4);
	param.push_back(2);
	param.push_back(1);
	param.push_back(1);
	param.push_back(2);
	param.push_back(4);

	int result = s.singleNumber(param);
	getchar();
}
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int totalHammingDistance(vector<int>& nums) 
	{
		int count = 0;

		int array_size = sizeof(int) * 8;
		vector<int> ones(array_size);

		int one = 1;

		for (int i = 0; i < array_size; i++)
		{
			int mask = (one << (31 - i));
			for (int j = 0; j < nums.size(); j++)
			{
				if (nums[j] & mask)
					ones[i]++;
			}

			count += (ones[i] * (nums.size() - ones[i]));
		}

		return count;
	}
};

int main()
{
	Solution s;

	vector<int> param{ 1,2,3,4 };

	int dist = s.totalHammingDistance(param);

	return 0;
}
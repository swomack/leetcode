#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	
	int find_max(vector<int>& a, vector<int>& b, int bit)
	{
		if (bit == -1)
			return 0;

		int mask = 1 << bit;
		vector<int> ones_a;
		vector<int> zeros_a;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] & mask)
				ones_a.push_back(a[i]);
			else
				zeros_a.push_back(a[i]);
		}


		vector<int> ones_b;
		vector<int> zeros_b;

		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] & mask)
				ones_b.push_back(b[i]);
			else
				zeros_b.push_back(b[i]);
		}


		if ((ones_a.size() > 0 && zeros_b.size() > 0) || (ones_b.size() > 0 && zeros_a.size() > 0))
		{
			int maxim = 1 << bit;

			int d1 = 0, d2 = 0;

			if (ones_a.size() > 0 && zeros_b.size() > 0)
			{
				d1 = find_max(ones_a, zeros_b, bit - 1);
			}

			if (ones_b.size() > 0 && zeros_a.size() > 0)
			{
				d2 = find_max(ones_b, zeros_a, bit - 1);
			}

			return max(maxim + d1, maxim + d2);
		}
		else
		{
			return find_max(a, b, bit - 1);
		}
	}

	int findMaximumXOR(vector<int>& nums) 
	{
		int number = 0;
		vector<int> ones;
		vector<int> zeros;

		int bit = 31;

		while ((ones.size() == 0 || zeros.size() == 0) && bit >= 0)
		{
			ones.clear();
			zeros.clear();

			bit--;

			int mask = 1 << bit;

			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] & mask)
					ones.push_back(nums[i]);
				else
					zeros.push_back(nums[i]);
			}
		}
		
		if (bit < 0)
			return number;

		number |= (1 << bit);

		number |= find_max(ones, zeros, bit - 1);

		return  number;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 3,10,5,25,2,8 };
	int maxim = s.findMaximumXOR(param);
	return 0;
}
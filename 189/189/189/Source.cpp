#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	void rotate(vector<int>& nums, int k) 
	{
		int size = nums.size();
		if (size == 0 || k % size == 0)
			return;

		int add = k % size;
		

		nums.resize(size + add);

		for (int i = size - 1; i >= 0; i--)
		{
			nums[i + add] = nums[i];
		}

		for (int i = 0; i < add; i++)
		{
			nums[i] = nums[size + i];
		}

		nums.resize(size);
		
	}
};

int main()
{
	Solution s;
	vector<int> param{ 1,2};
	s.rotate(param, 3);
	return 0;
}
#include <iostream>
#include <vector>

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
		int pos = 0;
		int loop = size;
		int num = nums[0];
		while (loop--)
		{
			int new_pos = (pos + add) % size;
			int temp = nums[new_pos];
			nums[new_pos] = num;
			num = temp;
			pos = new_pos;
		}
	}
};

int main()
{
	Solution s;
	return 0;
}
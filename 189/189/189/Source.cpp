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
		

		for (int i = 0; i < add; i++)
		{
			int pos = i;
			int num = nums[pos];

			while (pos < size)
			{
				int new_pos = pos + add;
				int temp = nums[new_pos % size];
				nums[new_pos % size] = num;
				num = temp;
				pos = new_pos;
			}
		}
		
	}
};

int main()
{
	Solution s;
	return 0;
}
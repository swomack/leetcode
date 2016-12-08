#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int removeDuplicates(vector<int>& nums) 
	{

		if (nums.size() <= 0)
			return 0;

		if (nums.size() == 1)
			return 1;

		vector<int> temp;
		vector<int> dup;
		int length = nums.size();

		int index = 0;
		while (index < length - 1)
		{
			if (nums[index] == nums[index + 1])
			{
				int val = nums[index];
				temp.push_back(val);

				index++;

				while (index < length && nums[index] == nums[index - 1])
				{
					dup.push_back(nums[index]);
					index++;
				}
			}
			else
			{
				int val = nums[index];
				temp.push_back(val);
				index++;
			}
		}

		index = 0;

		for (int i = 0; i < temp.size(); i++)
			nums[index++] = temp[i];

		for (int i = 0; i < dup.size(); i++)
			nums[index++] = dup[i];

		return temp.size();

		/*int length = nums.size();
		int head = 1;
		int tail = 1;

		while(head < length)
		{
			if (nums[head] != nums[head - 1])
			{
				int temp = nums[head];
				nums[head] = nums[tail];
				nums[tail] = temp;

				head++;
				tail++;
			}
			else
			{
				int value = nums[head];
				while (head < length && nums[head] == value)
					head++;

				if (head != length)
				{
					int temp = nums[head];
					nums[head] = nums[tail];
					nums[tail] = temp;

					head++;
					tail++;
				}
				
			}
		}

		return tail;*/
	}
};

int main()
{
	Solution s;
	vector<int> v{1, 1, 2, 2};
	int length = s.removeDuplicates(v);
	return 0;
}
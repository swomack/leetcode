#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int>& numbers, int target) 
	{
		vector<int> result;
	
		for (int i = 0, j = numbers.size() - 1; ;)
		{
			int res = numbers[i] + numbers[j];
			if ( res == target)
			{
				result.push_back(i + 1);
				result.push_back(j + 1);
				break;
			}
			else if (res < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}

		return result;
	}
};

int main()
{
	Solution s;

	vector<int> param{0,0,3,4};

	vector<int> res = s.twoSum(param, 0);

	getchar();
	return 0;
}
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

		int size = numbers.size() - 1;
	
		for (int i = 0; i <= size; i++)
		{
			int search = target - numbers[i];

			int start = i + 1;
			int end = size;

			while (start <= end)
			{
				int middle = (start + end) / 2;

				if (numbers[middle] == search)
				{
					result.push_back(i + 1);
					result.push_back(middle + 1);
					break;
				}
				else if (numbers[middle] > search)
				{
					end = middle - 1;
					continue;
				}
				else
				{
					start = middle + 1;
				}
			}

			if (result.size())
			{
				break;
			}
		}

		return result;
	}
};

int main()
{
	Solution s;

	vector<int> param{1, 2, 3, 4, 4, 35, 55};

	vector<int> res = s.twoSum(param, 8);

	getchar();
	return 0;
}
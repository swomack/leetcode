#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int trap(vector<int>& height) 
	{
		int result = 0;
		if (height.size() < 2)
			return result;

		int i = 0;
		int j = i + 1;;
		while (j < height.size())
		{
			if (height[j] <= height[j - 1])
			{
				j++;
				continue;
			}

			for (int k = j - 1; k > i && height[k] < height[j]; k--)
			{
				result += min(height[j], height[i]) - height[k];
				height[k] = height[j];
			}

			if (height[i] <= height[j])
				i = j;

			j++;
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> param{ 5,4,1,2 };

	int res = s.trap(param);

	return 0;
}
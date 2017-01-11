#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int maxArea(vector<int>& height) 
	{
		int start = 0;
		int end = height.size() - 1;

		int max_area = 0;

		while (start < end)
		{
			int area = (end - start) * min(height[start], height[end]);
			max_area = max(max_area, area);

			if (height[end] < height[start])
				end--;
			else
				start++;
		}

		return max_area;
	}
};

int main()
{
	Solution s;
	return 0;
}
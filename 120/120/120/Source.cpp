#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution 
{
public:
	int minimumTotal(vector<vector<int>>& triangle) 
	{
		int row = triangle.size() - 1;

		for (int i = 1; i <= row; i++)
		{
			triangle[i][0] += triangle[i - 1][0];
			triangle[i][i] += triangle[i - 1][i - 1];
		}

		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j < i; j++)
			{
				triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
			}
		}

		int min_path = INT_MAX;

		for (int i = 0; i < triangle[row].size(); i++)
		{
			min_path = min(min_path, triangle[row][i]);
		}

		return min_path;
	}
};

int main()
{
	Solution s;
	return 0;
}
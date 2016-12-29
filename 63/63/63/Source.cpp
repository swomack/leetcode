#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> results(m);

		for (int i = 0; i < m; i++)
			results[i].resize(n);

		for (int i = 0; i < m; i++)
		{
			if (obstacleGrid[i][0] == 1)
				break;
				
			results[i][0] = 1;
		}
			

		for (int i = 0; i < n; i++)
		{
			if (obstacleGrid[0][i] == 1)
				break;

			results[0][i] = 1;
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if(obstacleGrid[i][j] != 1)
					results[i][j] = results[i - 1][j] + results[i][j - 1];
			}
		}

		return results[m - 1][n - 1];
	}
};

int main()
{
	Solution s;

	vector<int> a{ 0,0,0 };
	vector<int> b{ 0,1,0 };
	vector<int> c{ 0,0,0 };

	vector<vector<int>> param{ a,b,c };

	int sol = s.uniquePathsWithObstacles(param);

	return 0;
}
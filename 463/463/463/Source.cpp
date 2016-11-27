#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int islandPerimeter(vector<vector<int>>& grid) 
	{
		int perimeter = 0;

		int row = grid.size();
		if (row == 0)
			return perimeter;

		int column = grid[0].size();
		if (column == 0)
			return perimeter;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (grid[i][j] != 1)
					continue;

				int nei = 0;

				if (i - 1 >= 0 && grid[i - 1][j] == 1)
					nei++;

				if (i + 1 < row && grid[i + 1][j] == 1)
					nei++;

				if (j - 1 >= 0 && grid[i][j - 1] == 1)
					nei++;

				if (j + 1 < column && grid[i][j + 1] == 1)
					nei++;

				perimeter += (4 - nei);
			}
		}


		

		return perimeter;
	}
};

int main()
{
	Solution s;

	return 0;
}
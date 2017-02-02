#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:

	int numIslands(vector<vector<char>>& grid)
	{
		int islands = 0;
		int row = grid.size();
		if (row == 0)
			return islands;

		int col = grid[0].size();
		if (col == 0)
			return islands;

		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == '1' && visited[i][j] == false)
				{
					islands++;
					visitNeighbours(grid, i, j, visited);
				}
			}
		}

		return islands;
	}


	void visitNeighbours(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited)
	{
		visited[i][j] = true;

		if (i > 0 && grid[i - 1][j] == '1' && visited[i - 1][j] == false)
		{
			visitNeighbours(grid, i - 1, j, visited);
		}

		if (j > 0 && grid[i][j - 1] == '1' && visited[i][j - 1] == false)
		{
			visitNeighbours(grid, i, j - 1, visited);
		}

		if (i < grid.size() - 1 && grid[i + 1][j] == '1' && visited[i + 1][j] == false)
		{
			visitNeighbours(grid, i + 1, j, visited);
		}

		if (j < grid[0].size() - 1 && grid[i][j + 1] == '1' && visited[i][j + 1] == false)
		{
			visitNeighbours(grid, i, j + 1, visited);
		}
	}
};

int main()
{
	Solution s;
	return 0;
}
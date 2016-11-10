#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int countBattleships(vector<vector<char>>& board) 
	{
		int height, width;

		height = board.size();
		width = board[0].size();

		int total_type = 0;


		vector<bool> visited(height * width);
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int index = i*width + j;
				visited[index] = false;
			}
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int index = i*width + j;

				if (visited[index])
					continue;

				visited[index] = true;

				if (board[i][j] == '.')
					continue;

				
				// now check which type, might need a hash

			}
		}
	}
};

int main()
{
	Solution s;
}
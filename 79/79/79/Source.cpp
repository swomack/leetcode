#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

	bool exist(vector<vector<char>>& board, string& word, int index, int i, int j, vector<vector<bool>>& visited)
	{
		if (board[i][j] != word[index])
			return false;

		if (index >= word.length() - 1)
			return true;
		
		visited[i][j] = true;
		bool res = false;

		if (i > 0 && !visited[i - 1][j])
			res = exist(board, word, index + 1, i - 1, j, visited);

		if(!res && i < board.size() - 1 && !visited[i + 1][j])
			res = exist(board, word, index + 1, i + 1, j, visited);

		if(!res && j > 0 && !visited[i][j - 1])
			res = exist(board, word, index + 1, i, j - 1, visited);

		if (!res && j <  board[0].size() - 1 && !visited[i][j + 1])
			res = exist(board, word, index + 1, i, j + 1, visited);

		visited[i][j] = false;
		return res;

	}

	bool exist(vector<vector<char>>& board, string word) 
	{
		if (word.length() <= 0)
			return false;

		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));

		int row = board.size();
		int col = board[0].size();

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				
				if (exist(board, word, 0, i, j, visited))
					return true;
			}
		}

		return false;
	}
};

int main()
{
	Solution s;
	return 0;
}
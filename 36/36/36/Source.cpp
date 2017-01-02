#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool isValidSudoku(vector<vector<char>>& board) 
	{
		// check all row
		for (int i = 0; i < 9; i++)
		{
			vector<int> rows(10);

			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;

				if (rows[board[i][j] - '0'] == 1)
					return false;

				rows[board[i][j] - '0'] = 1;
			}
		}

		// check all column
		for (int i = 0; i < 9; i++)
		{
			vector<int> columns(10);

			for (int j = 0; j < 9; j++)
			{
				if (board[j][i] == '.')
					continue;

				if (columns[board[j][i] - '0'] == 1)
					return false;

				columns[board[j][i] - '0'] = 1;
			}
		}


		//check all cells

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				vector<int> cells(10);

				int row_start = i * 3;
				int row_end = i * 3 + 3;

				int col_start = j * 3;
				int col_end = j * 3 + 3;

				for (int row = row_start; row < row_end; row++)
				{
					for (int col = col_start; col < col_end; col++)
					{
						if (board[row][col] == '.')
							continue;

						if (cells[board[row][col] - '0'] == 1)
							return false;
						cells[board[row][col] - '0'] = 1;
					}
				}
			}
		}

		return true;
	}
};

int main()
{
	Solution s;
	return 0;
}
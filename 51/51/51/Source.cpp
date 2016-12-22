#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	bool is_safe(vector<string>& matrix, int N, vector<int>& inserted_columns_row_index)
	{
		int last_inserted_row = inserted_columns_row_index[inserted_columns_row_index.size() - 1];
		int last_inserted_column = inserted_columns_row_index.size() - 1;

		if (last_inserted_column == 0) // first column is always valid
			return true;


		for (int i = 0; i < last_inserted_column; i++)
		{
			// if same row, then not valid
			if (inserted_columns_row_index[i] == last_inserted_row)
					return false;

			// if in the same angle, then not valid
			if (inserted_columns_row_index[i] + (last_inserted_column - i) == last_inserted_row || inserted_columns_row_index[i] + (i - last_inserted_column) == last_inserted_row)
				return false;
		}

		return true;
	}


	void NQueen(vector<string>& matrix, int column, int N, vector<vector<string>>& solutions, vector<int>& inserted_columns_row_index)
	{
		if (N < 4 && N > 1)
			return;

		if (column == N)
		{
			solutions.push_back(matrix);
			return;
		}

		for (int i = 0; i < N; i++)
		{
			matrix[i][column] = 'Q';
			inserted_columns_row_index.push_back(i);

			if (is_safe(matrix, N, inserted_columns_row_index))
				NQueen(matrix, column + 1, N, solutions, inserted_columns_row_index);

			matrix[i][column] = '.';
			inserted_columns_row_index.pop_back();
		}
	}

	vector<vector<string>> solveNQueens(int n) 
	{
		vector<string> matrix;

		vector<vector<string>> solutions;

		for (int i = 0; i < n; i++)
		{
			string s;

			for (int j = 0; j < n; j++)
				s.push_back('.');

			matrix.push_back(s);
		}

		vector<int> inserted_columns_row_index;
		NQueen(matrix, 0, n, solutions, inserted_columns_row_index);

		return solutions;
	}
};

int main()
{
	Solution s;
	return 0;
}
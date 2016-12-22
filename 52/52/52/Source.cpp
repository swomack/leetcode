#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:

	bool is_safe(int N, vector<int>& inserted_columns_row_index)
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


	void NQueen(vector<vector<int>>& matrix, int column, int N, int& solutions, vector<int>& inserted_columns_row_index)
	{
		if (column == N)
		{
			solutions++;
			return;
		}

		for (int i = 0; i < N; i++)
		{
			matrix[i][column] = 1;
			inserted_columns_row_index.push_back(i);

			if (is_safe(N, inserted_columns_row_index))
				NQueen(matrix, column + 1, N, solutions, inserted_columns_row_index);

			matrix[i][column] = 0;
			inserted_columns_row_index.pop_back();
		}
	}

	int totalNQueens(int n)
	{
		if (n < 4 && n > 1)
			return 0;

		if(n == 1)
			return 1;

		vector<vector<int>> matrix(n);

		int solutions = 0;

		for (int i = 0; i < n; i++)
		{
			matrix[i].resize(n);
		}

		vector<int> inserted_columns_row_index;
		NQueen(matrix, 0, n, solutions, inserted_columns_row_index);

		return solutions;
	}
};

int main()
{
	Solution s;
	int res = s.totalNQueens(4);
	return 0;
}
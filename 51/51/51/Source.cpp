#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	int get_row(vector<string>& matrix, int col, int N)
	{
		for (int i = 0; i < N; i++)
		{
			if (matrix[i][col] == 'Q')
				return i;
		}

		return -1;
	}

	bool is_safe(vector<string>& matrix, int N)
	{
		vector<int> positions;

		for (int i = 0; i < N; i++)
		{
			int row = get_row(matrix, i, N);

			if (row >= 0)
				positions.push_back(row);
		}

		if (positions.size() <= 1)
			return true;

		for (int i = 1; i < positions.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (positions[i] == positions[j])
					return false;

				if (positions[i] + (j - i) == positions[j] || positions[i] + (i - j) == positions[j])
					return false;
			}
		}

		return true;
	}


	void NQueen(vector<string>& matrix, int column, int N, vector<vector<string>>& solutions)
	{
		if (N < 4 && N > 1)
			return;

		if (column > N)
			return;

		else if (column == N)
		{
			solutions.push_back(matrix);
			return;
		}

		for (int i = 0; i < N; i++)
		{
			matrix[i][column] = 'Q';

			if (is_safe(matrix, N))
				NQueen(matrix, column + 1, N, solutions);

			matrix[i][column] = '.';
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

		NQueen(matrix, 0, n, solutions);



		return solutions;
	}
};

int main()
{
	Solution s;
	return 0;
}
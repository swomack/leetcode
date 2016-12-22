#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	bool is_safe(vector<string>& matrix, int N, vector<int>& rows)
	{
		if (rows.size() == 1)
			return true;

		for (int i = 1; i < rows.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (rows[i] == rows[j])
					return false;

				if (rows[i] + (j - i) == rows[j] || rows[i] + (i - j) == rows[j])
					return false;
			}
		}

		return true;
	}


	void NQueen(vector<string>& matrix, int column, int N, vector<vector<string>>& solutions, vector<int>& rows)
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
			rows.push_back(i);

			if (is_safe(matrix, N, rows))
				NQueen(matrix, column + 1, N, solutions, rows);

			matrix[i][column] = '.';
			rows.pop_back();
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

		vector<int> rows;
		NQueen(matrix, 0, n, solutions, rows);



		return solutions;
	}
};

int main()
{
	Solution s;
	return 0;
}
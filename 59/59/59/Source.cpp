#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	void fillLayer(int row_start, int row_end, int col_start, int col_end, int numbering_start, vector<vector<int>>& result)
	{
		if (row_start > row_end || col_start > col_end)
			return;

		for (int i = col_start; i < col_end; i++)
			result[row_start][i] = numbering_start++;

		for (int i = row_start; i <= row_end; i++)
			result[i][col_end] = numbering_start++;

		if (row_start != row_end)
		{
			for (int i = col_end - 1; i > col_start; i--)
				result[row_end][i] = numbering_start++;
		}
		
		if (col_start != col_end)
		{
			for (int i = row_end; i > row_start; i--)
				result[i][col_start] = numbering_start++;
		}
		

		fillLayer(row_start + 1, row_end - 1, col_start + 1, col_end - 1, numbering_start, result);
	}

	vector<vector<int>> generateMatrix(int n) 
	{
		vector<vector<int>> matrix(n);

		for (int i = 0; i < n; i++)
			matrix[i].resize(n);

		if (n == 0)
			return matrix;

		fillLayer(0, n - 1, 0, n - 1, 1, matrix);

		return matrix;
	}
};

int main()
{
	Solution s;

	vector<vector<int>> res = s.generateMatrix(5);

	return 0;
}
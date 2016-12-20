#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	void spiralLeftBottom(vector<vector<int>> matrix, int row_start, int row_end, int col_start, int col_end, vector<int> &result)
	{
		if (row_start > row_end || col_start > col_end)
			return;

		for (int i = col_end; i > col_start; i--)
			result.push_back(matrix[row_end][i]);

		for (int i = row_end; i >= row_start; i--)
			result.push_back(matrix[i][col_start]);

		spiralRightTop(matrix, row_start, row_end - 1, col_start + 1, col_end, result);
	}

	void spiralRightTop(vector<vector<int>> matrix, int row_start, int row_end, int col_start, int col_end, vector<int> &result)
	{
		if (row_start > row_end || col_start > col_end)
			return;

		for (int i = col_start; i < col_end; i++)
			result.push_back(matrix[row_start][i]);

		for (int i = row_start; i <= row_end; i++)
			result.push_back(matrix[i][col_end]);

		spiralLeftBottom(matrix, row_start + 1, row_end, col_start, col_end - 1, result);
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) 
	{
		vector<int> result;

		if (matrix.size() == 0 || matrix[0].size() == 0)
			return result;

		spiralRightTop(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, result);
		return result;
	}
};


int main()
{
	Solution s;
	vector<vector<int>> param;

	vector<int> a{ 1,2 };
	vector<int> b{ 3,4 };

	param.push_back(a);
	param.push_back(b);

	vector<int> res = s.spiralOrder(param);


	return 0;
}
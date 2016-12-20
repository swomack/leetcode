#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:


	void spiralSingleLayer(vector<vector<int>> matrix, int row_start, int row_end, int col_start, int col_end, vector<int> &result)
	{
		if (row_start > row_end || col_start > col_end)
			return;

		for (int i = col_start; i < col_end; i++)
			result.push_back(matrix[row_start][i]);

		for (int i = row_start; i <= row_end; i++)
			result.push_back(matrix[i][col_end]);

		if (row_start != row_end)
		{
			for (int i = col_end - 1; i >= col_start; i--)
				result.push_back(matrix[row_end][i]);
		}
		
		if (col_start != col_end)
		{
			for (int i = row_end - 1; i > row_start; i--)
				result.push_back(matrix[i][col_start]);
		}

		

		spiralSingleLayer(matrix, row_start + 1, row_end - 1, col_start + 1, col_end - 1, result);
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) 
	{
		vector<int> result;

		if (matrix.size() == 0 || matrix[0].size() == 0)
			return result;

		spiralSingleLayer(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, result);
		return result;
	}
};


int main()
{
	Solution s;
	vector<vector<int>> param;

	vector<int> a{ 3 };
	vector<int> b{ 4 };

	param.push_back(a);
	param.push_back(b);

	vector<int> res = s.spiralOrder(param);


	return 0;
}
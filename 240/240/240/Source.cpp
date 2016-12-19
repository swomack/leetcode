#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:

	bool searchMatrixHelper(vector<vector<int>>& matrix, int row_start, int row_end, int col_start, int col_end, int target)
	{
		if (row_start > row_end || col_start > col_end)
			return false;

		int row_middle = (row_start + row_end) / 2;
		int index = col_start - 1;

		for (int i = col_start; i <= col_end; i++)
		{
			if (matrix[row_middle][i] == target)
				return true;

			if (matrix[row_middle][i] < target)
			{
				index++;
				continue;
			}


			if (matrix[row_middle][i] > target)
				break;

		}

		return searchMatrixHelper(matrix, row_start, row_middle - 1, index + 1, col_end, target) || searchMatrixHelper(matrix, row_middle + 1, row_end, col_start, index, target);
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		return searchMatrixHelper(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
	}
};

int main()
{
	Solution s;

	vector<vector<int>> param;
	vector<int> a{ 1, 4, 7, 11,15 };
	vector<int> b{ 2, 5, 8, 12,19 };
	vector<int> c{ 3, 6, 9, 16,22 };
	vector<int> d{ 10,13,14,17,24 };
	vector<int> e{ 18,21,23,26,30 };


	param.push_back(a);
	param.push_back(b);
	param.push_back(c);
	param.push_back(d);
	param.push_back(e);
	

	bool res = s.searchMatrix(param, 5);

	return 0;
}
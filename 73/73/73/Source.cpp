#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	void setZeroes(vector<vector<int>>& matrix) 
	{
		if (matrix.size() == 0)
			return;

		if (matrix[0].size() == 0)
			return;

		vector<int> row_map(matrix.size());
		vector<int> col_map(matrix[0].size());

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					row_map[i] = 1;
					col_map[j] = 1;
				}
			}
		}

		for (int i = 0; i < row_map.size(); i++)
		{
			if (row_map[i])
			{
				for (int j = 0; j < matrix[i].size(); j++)
					matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < col_map.size(); i++)
		{
			if (col_map[i])
			{
				for (int j = 0; j < matrix.size(); j++)
					matrix[j][i] = 0;
			}
		}
	}
};

int main()
{
	Solution s;
	return 0;
}
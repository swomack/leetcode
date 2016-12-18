#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
		int row = matrix.size();
		int col = matrix[0].size();

		bool ret = false;

		int left = 0;
		int right = row * col - 1;

		while (left <= right)
		{
			int middle = (left + right) / 2;

			int row1 = middle / col;
			int col1 = middle % col;

			if (matrix[row1][col1] == target)
			{
				ret = true;
				break;
			}
			else if (matrix[row1][col1] > target)
			{
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
		}

		return ret;
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

	bool res = s.searchMatrix(param, 4);

	return 0;
}
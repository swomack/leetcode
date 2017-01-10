#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	void rotate(vector<vector<int>>& matrix) 
	{
		int n = matrix.size();

		vector<vector<int>> rotated(n);

		for (int i = 0; i < n; i++)
			rotated[i].resize(n);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				rotated[j][n - 1 - i] = matrix[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = rotated[i][j];
			}
		}
	}
};

int main()
{
	Solution s;
	return 0;
}
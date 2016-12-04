#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> generate(int numRows) 
	{
		vector<vector<int>> result(numRows);

		for (int i = 1; i <= numRows; i++)
		{
			vector<int> row(i);
			result[i - 1] = row;
		}

		for (int i = 1; i <= numRows; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (j == 1 || j == i)
				{
					result[i - 1][j - 1] = 1;
					continue;
				}
				
				result[i - 1][j - 1] = result[i - 2][j - 2] + result[i - 2][j - 1];
			}
		}

		return result;
	}
};

int main()
{
	Solution s;

	vector<vector<int>> result = s.generate(5);

	return 0;
}
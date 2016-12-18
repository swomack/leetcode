#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct comp
{
	bool operator () (int lhs, int rhs)
	{
		return rhs < lhs;
	}
};

class Solution 
{
public:

	/*int quickSelect(vector<int>& all, int i, int j, int k)
	{

	}*/

	int kthSmallest(vector<vector<int>>& matrix, int k) 
	{
		vector<int> all;

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
				all.push_back(matrix[i][j]);
		}

		sort(all.begin(), all.end(), comp());

		//int res = quickSelect(all, 0, all.size() - 1, k);

		return all[k-1];
	}
};

int main()
{
	Solution s;
	return 0;
}
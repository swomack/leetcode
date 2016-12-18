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
	void swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	int partition(vector<int>& all, int i, int j, int pivot_index)
	{
		swap(&all[pivot_index], &all[j]);

		int start = i;

		for (; i < j; i++)
		{
			if (all[i] < all[j])
			{
				swap(&all[i], &all[start]);
				++start;
			}
		}

		swap(&all[start], &all[j]);

		return start;
	}
	
	int quickSelect(vector<int>& all, int i, int j, int k)
	{
		if (i == j)
			return all[i];

		int pivot_index = i + floor(rand() % (j - i + 1));

		pivot_index = partition(all, i, j, pivot_index);

		if (pivot_index == k)
			return all[k];

		if (pivot_index > k)
			return quickSelect(all, i, pivot_index - 1, k);
		else
			return quickSelect(all, pivot_index + 1, j, k);
	}

	int kthSmallest(vector<vector<int>>& matrix, int k) 
	{
		vector<int> all;

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
				all.push_back(matrix[i][j]);
		}

		//sort(all.begin(), all.end(), comp());

		int res = quickSelect(all, 0, all.size() - 1, k - 1);

		return res;
	}
};

int main()
{
	Solution s;
	return 0;
}
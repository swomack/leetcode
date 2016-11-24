#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
	{
		int count = 0;
		int size = A.size();

		unordered_map<int, int> map;
	

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				map[A[i] + B[j]]++;
			}
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int sum = C[i] + D[j];
				count += map[-sum];
			}
		}

		return count;
	}
};

int main()
{
	Solution s;

	vector<int> param1{1,2};
	vector<int> param2{ -1,-1 };
	vector<int> param3{ -1,2 };
	vector<int> param4{ 0,2 };

	int res = s.fourSumCount(param1, param2, param3, param4);

	return 0;
}
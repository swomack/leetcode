#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution 
{
public:

	unordered_map<long long int, long long int> comb_map;

	long long int get_comb(long long int n, long long int c)
	{
		c = n - c > c ? c : n - c;

		if (comb_map[n + c])
			return comb_map[n + c];

		long long int comb = 1;
		long long int k = n + c;

		for (long long int i = 1; i <= c; i++, n--)
		{
			comb *= n;
			comb /= i;
		}

		comb_map[k] = comb;

		return comb;
	}

	vector<int> getRow(int rowIndex) 
	{
		comb_map.clear();

		vector<int> result;

		for (int i = 0; i <= rowIndex; i++)
			result.push_back(get_comb(rowIndex, i));

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> res = s.getRow(3);
	return 0;
}
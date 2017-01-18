#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution 
{
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) 
	{
		vector<int> uglys(n);
		vector<int> prev_gen(primes.size());

		uglys[0] = 1;

		for (int i = 1; i < n; i++)
		{
			uglys[i] = INT_MAX;

			for (int j = 0; j < primes.size(); j++)
				uglys[i] = min(uglys[i], primes[j] * uglys[prev_gen[j]]);

			for (int j = 0; j < primes.size(); j++)
			{
				while (uglys[i] >= uglys[prev_gen[j]] * primes[j])
					prev_gen[j]++;
			}
		}

		return uglys[n - 1];
	}
};

int main()
{
	Solution s;
	return 0;
}
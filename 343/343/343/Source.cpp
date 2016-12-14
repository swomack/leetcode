#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int integerBreak(int n) 
	{
		vector<int> res(n + 1);

		res[1] = 1;
		res[2] = 1;

		for (int i = 3; i <= n; i++)
		{
			int maximum = 0;
			for (int j = 1; j <= i / 2; j++)
			{
				maximum = max(maximum, res[j] * res[i - j]);
				maximum = max(maximum, (i - j) * j);
				maximum = max(maximum, res[i - j] * j);
				maximum = max(maximum, (i - j) * res[j]);
			}

			res[i] = maximum;
		}

		return res[n];
	}
};

int main()
{
	Solution s;
	int res = s.integerBreak(10);
	return 0;
}
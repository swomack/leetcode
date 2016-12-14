#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution 
{
public:
	int countNumbersWithUniqueDigits(int n) 
	{
		vector<int> count(n + 1);

		count[0] = 1;
		count[1] = 10;

		int mult = 9;
		int run = 9;

		for (int i = 2; i <= n; i++)
		{
			count[i] = count[i - 1] + (mult * run);
			run = mult * run;
			mult--;
		}

		return count[n];
	}
};

int main()
{
	Solution s;
	return 0;
}
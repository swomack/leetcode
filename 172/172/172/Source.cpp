#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int trailingZeroes(int n) 
	{
		int twos = 0;
		int fives = 0;

	
		long num = (long)n;
		long divTwo = 2;
		while (true)
		{
			long add = floor(num / divTwo);

			if (add == 0)
				break;

			twos += add;
			divTwo *= 2;
		}

		num = n;
		long divFive = 5;
		while (true)
		{
			int add = floor(num / divFive);

			if (add == 0)
				break;

			fives += add;
			divFive *= 5;
		}

		return min(twos, fives);
	}
};

int main()
{
	Solution s;
	int res = s.trailingZeroes(1808548329);
	return 0;
}
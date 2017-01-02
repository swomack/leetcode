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

		for (int i = 2; i <= n; i++)
		{
			int num = i;

			while (num && num % 2 == 0)
			{
				twos++;
				num /= 2;
			}

			while (num && num % 5 == 0)
			{
				fives++;
				num /= 5;
			}
		}

		return min(twos, fives);
	}
};

int main()
{
	Solution s;
	return 0;
}
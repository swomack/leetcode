#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) 
	{
		long gap = 9;
		long digit = 1;
		
		long number = 0;

		while (true)
		{
			if (n < (gap * digit))
				break;

			number += gap;
			n -= (gap * digit);
			gap *= 10;
			digit++;
		}

		number += ceil((double)n / digit);
		long d = n % digit;

		if (d)
			d = digit - d;

		long ans = -1;

		while (d >= 0)
		{
			d--;
			ans = number % 10;
			number /= 10;
		}

		return ans;
	}
};

int main()
{
	Solution s;
	int k = s.findNthDigit(10);
	return 0;
}
#include <iostream>
#include <cmath>
#include <climits>


using namespace std;

class Solution 
{
public:
	int reverse_positive(long long x)
	{
		long long res = 0;
		while (x)
		{
			long long digit = x % 10;
			x /= 10;
			res *= 10;
			res += digit;

			if (res < INT_MIN || res > INT_MAX)
				return 0;
		}

		return res;
	}

	int reverse(int x) 
	{
		int res = reverse_positive(abs(x));

		if (x < 0)
			return -1 * res;

		return res;
	}
};

int main()
{
	Solution s;
	int res = s.reverse(1534236469);
	return 0;
}
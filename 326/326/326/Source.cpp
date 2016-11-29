#include <iostream>
#include <cmath>

using namespace std;


class Solution 
{
public:
	bool isPowerOfThree(int n) 
	{
		if (n <= 0)
			return false;

		if (n % 3) return n == 1;

		if (n % 9) return n == 3;
		//
		//int log_val = (log10(n)) / log10(3);

		//// if 3 ^ log_val = n then it is a power of 3
		//return ((int)pow(3, log_val)) == n;

		// this is the fastest
		// if the number is power of 3, then it has to divide the maximum 3^power integer = 3 ^ 19 = 1162261467
		// also 3 ^ 19 will be divisible by only 3^k (its obvious) --- 3 * 3 * 3 .... / 3 * 3 ** 3
		return 1162261467 % n == 0;
	}
};


int main()
{
	Solution s;
	bool res = s.isPowerOfThree(243);
	res = s.isPowerOfThree(0);
	res = s.isPowerOfThree(1);
	res = s.isPowerOfThree(2);
	res = s.isPowerOfThree(3);
	res = s.isPowerOfThree(-3);
	res = s.isPowerOfThree(-1);
	res = s.isPowerOfThree(27);
	res = s.isPowerOfThree(26);
	res = s.isPowerOfThree(81);

	return 0;
}
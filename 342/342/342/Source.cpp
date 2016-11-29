#include <iostream>

using namespace std;

class Solution 
{
public:
	bool isPowerOfFour(int num) 
	{
		if (num <= 0)
			return false;

		if (num % 4)
			return num == 1;

		if (num % 16)
			return num == 4;

		int log_val = log10(num) / log10(2);

		if (log_val % 2)
			return false;

		return ((int)(pow(2, log_val)) == num);
	}
};


int main()
{
	Solution s;
	bool res = s.isPowerOfFour(16);
	return 0;
}
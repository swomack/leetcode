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

		if (num & (num - 1))
			return false;

		while (num > 1)
			num >>= 2;

		return num == 1;
	}
};


int main()
{
	Solution s;
	bool res = s.isPowerOfFour(16);
	return 0;
}
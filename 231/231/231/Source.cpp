#include <iostream>

using namespace std;

class Solution 
{
public:
	bool isPowerOfTwo(int n) 
	{
		if (n <= 0)
			return false;

		return __builtin_popcount(n) == 1;
	}
};

int main()
{
	Solution s;
	bool res = s.isPowerOfTwo(10);
	return 0;
}
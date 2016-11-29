#include <iostream>

using namespace std;

class Solution 
{
public:
	bool isPowerOfTwo(int n) 
	{
		return (n > 0 && ((n & (n - 1)) == 0));
	}
};

int main()
{
	Solution s;
	bool res = s.isPowerOfTwo(128);
	return 0;
}
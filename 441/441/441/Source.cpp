#include <iostream>
#include <cmath>

using namespace std;

class Solution 
{
public:
	int arrangeCoins(int n) 
	{
		unsigned long long k = (unsigned long long)n;
		k *= 8;
		k += 1;

		k = (int)sqrt(k);

		if (k % 2 == 0)
			k -= 1;
		
		return (k - 1) / 2;
	}
};

int main()
{
	Solution s;
	int res = s.arrangeCoins(2147483647);
	return 0;
}
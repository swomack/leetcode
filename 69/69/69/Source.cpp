#include <iostream>


using namespace std;

class Solution 
{
public:
	int mySqrt(int x) 
	{
		if (x == 0)
			return 0;
		
		long long a = 1;
		long long b = x / 2;

		long long root = 1;

		while (a <= b)
		{
			root = (a + b) / 2;

			long long sqr = root * root;

			if (sqr == (long long)x)
			{
				break;
			}
			else if (sqr < (long long)x)
			{
				a = root + 1;
			}
			else
			{
				b = root - 1;
			}
		}

		if (root * root > (long long)x)
			root--;

		return root;
	}
};

int main()
{
	Solution s;
	int r = s.mySqrt(34654231);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution 
{
public:
	bool isPerfectSquare(int num) 
	{
		long low = 1;
		long high = num;

		while (low <= high)
		{
			long mid = (low + high) / 2;

			if (mid * mid == num)
				return true;

			if (mid * mid > num)
				high = mid - 1;
			else
				low = mid + 1;
		}

		return false;
	}
};

int main()
{
	Solution s;
	bool res = s.isPerfectSquare(16);
	return 0;
}
#include <iostream>

using namespace std;

#define BAD_VERSION 1702766719

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
	if (version >= BAD_VERSION)
		return true;

	return false;
}

class Solution 
{
public:
	int firstBadVersion(int n) 
	{
		long long first = 1;
		long long last = (long long)n;

		long long ret = -1;

		while (first <= last)
		{
			long long middle = (first + last) / 2;

			if (isBadVersion(middle))
			{
				ret = middle;
				last = middle - 1;
			}
			else
				first = middle + 1;
		}

		return ret;
	}
};

int main()
{
	Solution s;
	int k = s.firstBadVersion(2126753390);
	return 0;
}
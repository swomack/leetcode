#include <iostream>

using namespace std;

class Solution 
{
public:

	int kernighan_number_of_one(int n)
	{
		int count = 0;

		while (n)
		{
			n &= (n - 1); // make the most significant beat 0, rest will be same, the number will be reduced to the next one bit
			count++;
		}

		return count;
	}

	int pop_count(int n)
	{
		return __builtin_popcount(n);
	}

	int hammingDistance(int x, int y) 
	{
		int exor = x ^ y;
		return pop_count(exor);
	}
};

int main()
{
	Solution s;
	return 0;
}
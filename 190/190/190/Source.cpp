#include <iostream>
#include <bitset>

using namespace std;

class Solution 
{
public:
	uint32_t reverseBits(uint32_t n) 
	{
		if (n == 0)
			return 0;

		unsigned int mask = 1;
		unsigned int res = 0;
		for (int i = 0; i < 31; i++)
		{
			res |= ((mask & n) >> i);
			res <<= 1;
			mask <<= 1;
		}

		res |= ((mask & n) >> 31);

		return res;
	}
};

int main()
{
	Solution s;
	int res = s.reverseBits(2147483648);
	return 0;
}
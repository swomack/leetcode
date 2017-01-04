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

		bitset<32> bits(n);
		unsigned int res = 0;
		for (int i = 0; i < 31; i++)
		{
			res |= bits[i];
			res <<= 1;
		}

		res |= bits[31];

		return res;
	}
};

int main()
{
	Solution s;
	int res = s.reverseBits(0);
	return 0;
}
#include <iostream>
#include <bitset>

using namespace std;

class Solution 
{
public:
	int hammingWeight(uint32_t n) 
	{
		bitset<32> bits(n);
		return bits.count();
	}
};


int main()
{
	Solution s;
	int bit = s.hammingWeight(11);
	return 0;
}
#include <iostream>

using namespace std;

class Solution 
{
public:
	int hammingWeight(uint32_t n) 
	{
		return __builtin_popcount(n);
	}
};


int main()
{

	return 0;
}
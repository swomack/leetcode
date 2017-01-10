#include <iostream>
#include <climits>


using namespace std;

class Solution 
{
public:
	int findComplement(int num) 
	{
		if (num == 0)
			return 1;

		num ^= INT_MAX;
		
		int mask = 1 << 30;
		while (num & mask)
		{
			int mask2 = mask ^ INT_MAX;
			num &= mask2;
			mask >>= 1;
		}

		return num;
	}
};

int main()
{
	Solution s;
	int k = s.findComplement(5);
	return 0;
}
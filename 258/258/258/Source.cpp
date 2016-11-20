#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int addDigits(int num) 
	{
		if (num == 0)
			return 0;

		int remainder = (num % 9);
		return remainder ? remainder : 9;
	}
};

int main()
{
	Solution s;

	int res = s.addDigits(125465);

	getchar();
}
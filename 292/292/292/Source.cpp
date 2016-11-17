#include <iostream>


using namespace std;

// solution for this problem lies in the fact that 1st mover wins when there are 1, 2, 3 stones and second mover win when there are 4 stones
// If there are 4 stones, any move will position the second mover in first moved pos

class Solution 
{
public:
	bool canWinNim(int n) 
	{
		if (n % 4)
			return true;

		return false;
	}
};

int main()
{
	Solution s;
	bool res = s.canWinNim(10);
	getchar();
}
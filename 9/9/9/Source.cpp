#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) 
	{
		if (x < 0 || (x > 0 && x%10 == 0))
			return false;

		int num = x;
		int rev_num = 0;
		while (x)
		{
			int digit = x % 10;
			rev_num *= 10;
			rev_num += digit;
			x /= 10;
		}

		return rev_num == num;
	}
};

int main()
{
	Solution s;
	bool ret = s.isPalindrome(123);
	return 0;
}
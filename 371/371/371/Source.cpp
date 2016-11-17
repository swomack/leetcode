#include <iostream>

using namespace std;

class Solution 
{
public:
	int getSum(int a, int b) 
	{
		int sum = (a == 0 ? b : ((b == 0) ? a : 0));
		if (sum)
			return sum;

		sum = a ^ b;
		int carry = (a & b);

		while (carry)
		{
			carry <<= 1;
			int temp = sum ^ carry;
			carry &= sum;
			sum = temp;
		}

		return sum;
	}
};

int main()
{
	Solution s;
	int result = s.getSum(1, 2);
	getchar();
}
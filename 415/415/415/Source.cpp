#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	void swap(string* a, string* b)
	{
		string temp = *a;
		*a = *b;
		*b = temp;
	}

	string addStrings(string num1, string num2) 
	{
		string res;
	
		if (num2.length() > num1.length())
			swap(&num1, &num2);

		int index2 = num2.length() - 1;
		int index1 = num1.length() - 1;
		int carry = 0;
		int sub = 2 * '0';
		while (index2 >= 0)
		{
			int res_digit = num1[index1--] + num2[index2--] - sub + carry;
			carry = res_digit / 10;
			res_digit %= 10;
			res.push_back(res_digit + '0');
		}

		sub = '0';

		while (index1 >= 0)
		{
			int res_digit = num1[index1--] - sub + carry;
			carry = res_digit / 10;
			res_digit %= 10;
			res.push_back(res_digit + '0');
		}

		if (carry)
		{
			res.push_back('1');
		}

		reverse(res.rbegin(), res.rend());

		return res;
	}
};

int main()
{
	Solution s;

	string res = s.addStrings("123", "1234");

	return 0;
}
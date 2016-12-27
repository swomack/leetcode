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
		reverse(num1.rbegin(), num1.rend());
		reverse(num2.rbegin(), num2.rend());

		if (num2.length() > num1.length())
			swap(&num1, &num2);

		int index = 0;
		int carry = 0;
		int sub = 2 * '0';
		while (index < num2.length())
		{
			int res_digit = num1[index] + num2[index] - sub + carry;
			carry = res_digit / 10;
			res_digit %= 10;

			res.push_back(res_digit + '0');
			index++;
		}

		sub = '0';

		while (index < num1.length())
		{
			int res_digit = num1[index] - sub + carry;
			carry = res_digit / 10;
			res_digit %= 10;

			res.push_back(res_digit + '0');
			index++;
		}

		if (carry)
			res.push_back('1');

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
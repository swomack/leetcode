#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int la = a.length();
		int lb = b.length();

		string res;
		int carry = 0;
		while (la && lb)
		{
			la--;
			lb--;
			int digit = (a[la] - '0') ^ (b[lb] - '0') ^ carry;
			res.push_back('0' + digit);
			carry = (((a[la] - '0') || (b[lb] - '0')) & carry) || ((a[la] - '0') && (b[lb] - '0'));
		}

		while (la)
		{
			la--;
			int digit = (a[la] - '0') ^ carry;
			res.push_back('0' + digit);
			carry = (a[la] - '0') && carry;
		}

		while (lb)
		{
			lb--;
			int digit = (b[lb] - '0') ^ carry;
			res.push_back('0' + digit);
			carry = (b[lb] - '0') && carry;
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
	string res = s.addBinary("0", "0");
	return 0;
}
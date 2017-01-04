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
		while (la-- && lb--)
		{
			int digit = (a[la] - '0') ^ (b[lb] - '0') ^ carry;
			res.push_back('0' + digit);
			carry = (((a[la] - '0') || (b[lb] - '0')) & carry) || ((a[la] - '0') && (b[lb] - '0'));
		}
	}
};

int main()
{
	Solution s;
	return 0;
}
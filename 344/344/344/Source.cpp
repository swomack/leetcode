#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {

		for (int i = -1, j = s.length(); ++i < --j;)
		{
			/*char tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;*/

			s[i] ^= s[j];
			s[j] ^= s[i];
			s[i] ^= s[j];
		}

		//reverse(begin(s), end(s));

		return s;
	}
};

int main()
{
	Solution s;
	string str = s.reverseString("Hello");
	cout << str << endl;
	getchar();
}
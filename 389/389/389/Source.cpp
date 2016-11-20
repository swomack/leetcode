// This problem is exactly like the single integer problem

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	char findTheDifference(string s, string t) 
	{
		int char_xor = 0;

		for_each(s.begin(), s.end(), [&char_xor](char element) {
			char_xor ^= element;
		});

		for_each(t.begin(), t.end(), [&char_xor](char element) {
			char_xor ^= element;
		});

		return char_xor;

	}
};

int main()
{
	Solution s;

	char res = s.findTheDifference("abcd", "abecd");

	getchar();
}
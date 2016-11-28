#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int longestPalindrome(string s) 
	{
		unordered_map<char, int> map;

		int count = 0;

		int single_char = 0;

		for (int i = 0; i < s.length(); i++)
		{
			map[s[i]]++;

			int val = map[s[i]];

			if (val % 2)
			{
				single_char++;
			}
			else
			{
				single_char--;
				count++;
			}
		}

		return ((count * 2) + (single_char > 0 ? 1 : 0));
	}
};

int main()
{
	Solution s;

	int result = s.longestPalindrome("abccccdd");

	return 0;
}
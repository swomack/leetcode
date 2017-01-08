#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	bool checkPal(string& s)
	{
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			if (s[i] != s[j])
				return false;
		}

		return true;
	}

	bool isPalindrome(string s) 
	{
		string new_s;

		for (int i = 0; i < s.length(); i++)
		{
			if (isalnum(s[i]))
			{
				if (isalpha(s[i]))
					new_s.push_back(tolower(s[i]));
				else
					new_s.push_back(s[i]);
			}
		}

		return checkPal(new_s);
	}
};

int main()
{
	Solution s;
	return 0;
}
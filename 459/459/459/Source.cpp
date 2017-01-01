#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool repeatedSubstringPattern(string str) 
	{
		if (str.length() <= 1)
			return false;

		string pattern;
	
		for (int i = 0; i < str.length() / 2; i++)
		{
			pattern.push_back(str[i]);

			if (patternCheck(str, pattern))
				return true;
		}

		return false;
	}

	bool patternCheck(string& str, string& pattern)
	{
		if (str.length() % pattern.length())
			return false;

		for (int i = 0; i < str.length(); i += pattern.length())
		{
			string substr = str.substr(i, pattern.length());

			if (substr != pattern)
				return false;
		}

		return true;
	}
};

int main()
{
	Solution s;
	bool res = s.repeatedSubstringPattern("abaababaab");
	return 0;
}
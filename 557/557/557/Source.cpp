#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution 
{
public:
	string reverseWords(string s) 
	{
		stack<char> reverse_chars;
		string result;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ' || s[i] == '\t')
			{
				while (!reverse_chars.empty())
				{
					result.push_back(reverse_chars.top());
					reverse_chars.pop();
				}

				result.push_back(s[i]);

				continue;
			}

			reverse_chars.push(s[i]);
		}

		while (!reverse_chars.empty())
		{
			result.push_back(reverse_chars.top());
			reverse_chars.pop();
		}

		return result;
	}
};


int main()
{
	Solution s;
	return 0;
}
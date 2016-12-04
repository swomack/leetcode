#include <iostream>
#include <stack>

using namespace std;

class Solution 
{
public:
	bool isValid(string s) 
	{
		stack<char> stk;



		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			{
				if (stk.empty())
					return false;

				switch (s[i])
				{
				case ')':
					if (stk.top() == '(')
					{
						stk.pop();
					}
					else
					{
						return false;
					}

					break;

				case '}':
					if (stk.top() == '{')
					{
						stk.pop();
					}
					else
					{
						return false;
					}

					break;

				case ']':
					if (stk.top() == '[')
					{
						stk.pop();
					}
					else
					{
						return false;
					}

					break;
				}
			}
			else
			{
				stk.push(s[i]);
			}
		}

		return stk.empty();
	}
};

int main()
{
	Solution s;
	bool res = s.isValid("[]");
	return 0;
}
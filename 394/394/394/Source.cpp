#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	string decodeString(string s) 
	{
		stack<int> nums;
		stack<string> strs;

		strs.push("");
		int i = 0;

		int number = 0;

		while (i < s.length())
		{
			if (s[i] == ']' && ++i)
			{
				string kk;

				while (nums.top()--)
				{
					kk += strs.top();
				}

				strs.pop();
				nums.pop();

				strs.top() += kk;
			}
			else if (s[i] == '[' && ++i)
			{
				nums.push(number);
				strs.push("");
				number = 0;
			}
			else if(isdigit(s[i]))
			{
				number *= 10;
				number += (s[i] - '0');
				i++;
			}
			else
			{
				strs.top().push_back(s[i++]);
			}
		}

		while (strs.size() > 1)
		{
			string a = strs.top();
			strs.pop();
			strs.top() += a;
		}

		return strs.top();
	}
};


int main()
{
	Solution s;
	string res = s.decodeString("2[ab3[2[ab]]]");
	return 0;
}
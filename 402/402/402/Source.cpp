#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:

	string removeKdigits(string num, int k) 
	{
		
		if (k >= num.length())
			return "0";
		
		stack<char> values;
		string result;

		values.push(num[0]);

		for (int i = 1; i < num.length(); i++)
		{
			while (k && !values.empty() && values.top() > num[i])
			{
				values.pop();
				k--;
			}

			if (num[i] == '0' && values.empty())
				continue;

			values.push(num[i]);
		}

		while (k && !values.empty())
		{
			values.pop();
			k--;
		}


		if (values.size() <= 0)
			result = "0";
		else
		{
			result.resize(values.size());

			while (!values.empty())
			{
				result[values.size() - 1] = values.top();
				values.pop();
			}
		}
		

		return result;
	}
};

int main()
{
	Solution s;

	string res = s.removeKdigits("5617218", 4);

	return 0;
}
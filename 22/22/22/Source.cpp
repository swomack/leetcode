#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void backtrack(string& parenthesis, int open, int close, vector<string>& result)
	{
		if (open == 0 && close == 1)
		{
			parenthesis.push_back(')');
			result.push_back(parenthesis);
			parenthesis.pop_back();
			return;
		}

		if (open)
		{
			parenthesis.push_back('(');
			backtrack(parenthesis, open - 1, close, result);
			parenthesis.pop_back();
		}
		

		if (close > open)
		{
			parenthesis.push_back(')');
			backtrack(parenthesis, open, close - 1, result);
			parenthesis.pop_back();
		}
	}

	vector<string> generateParenthesis(int n) 
	{
		vector<string> result;

		if (n <= 0)
			return result;

		string parenthesis;
		parenthesis.push_back('(');

		backtrack(parenthesis, n - 1, n, result);

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

	bool isValid(string& parenthesis)
	{
		int count = 0;

		for (int i = 0; i < parenthesis.length(); i++)
		{
			if (parenthesis[i] == '(')
				count++;
			else
				count--;

			if (count < 0)
				return false;
		}

		return true;
	}

	void backtrack(string& parenthesis, int n, vector<string>& result, int open)
	{
		if (n == 1)
		{
			parenthesis.push_back(')');

			if (isValid(parenthesis))
				result.push_back(parenthesis);

			parenthesis.pop_back();
			return;
		}

		if (open)
		{
			parenthesis.push_back('(');
			backtrack(parenthesis, n - 1, result, open - 1);
			parenthesis.pop_back();
		}
		

		parenthesis.push_back(')');

		if (isValid(parenthesis))
			backtrack(parenthesis, n - 1, result, open);
		
		parenthesis.pop_back();
	}

	vector<string> generateParenthesis(int n) 
	{
		vector<string> result;

		if (n <= 0)
			return result;

		string parenthesis;
		parenthesis.push_back('(');

		backtrack(parenthesis, 2 * n - 1, result, n - 1);

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}
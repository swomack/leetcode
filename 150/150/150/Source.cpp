#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution 
{
public:
	int evalRPN(vector<string>& tokens) 
	{
		stack<int> numbers;

		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+")
			{
				int a = numbers.top();
				numbers.pop();
				int b = numbers.top();
				numbers.pop();

				numbers.push(a + b);
			}
			else if (tokens[i] == "-")
			{
				int a = numbers.top();
				numbers.pop();
				int b = numbers.top();
				numbers.pop();

				numbers.push(b - a);
			}
			else if (tokens[i] == "*")
			{
				int a = numbers.top();
				numbers.pop();
				int b = numbers.top();
				numbers.pop();

				numbers.push(a * b);
			}
			else if (tokens[i] == "/")
			{
				int a = numbers.top();
				numbers.pop();
				int b = numbers.top();
				numbers.pop();

				numbers.push(b / a);
			}
			else
			{
				numbers.push(stoi(tokens[i]));
			}
		}

		return numbers.top();
	}
};

int main()
{
	Solution s;
	return 0;
}
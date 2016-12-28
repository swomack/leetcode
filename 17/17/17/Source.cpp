#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:

	void backtrack(vector<string>& map, vector<string> &result, string& digits, string& construct, int index)
	{
		if (index == digits.length() - 1)
		{
			int map_pos = digits[index] - '0' - 2;

			string letters = map[map_pos];

			for (int i = 0; i < letters.length(); i++)
			{
				construct.push_back(letters[i]);
				result.push_back(construct);
				construct.pop_back();
			}

			return;
		}


		int map_pos = digits[index] - '0' - 2;

		string letters = map[map_pos];

		for (int i = 0; i < letters.length(); i++)
		{
			construct.push_back(letters[i]);
			backtrack(map, result, digits, construct, index + 1);
			construct.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) 
	{
		vector<string> map{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

		vector<string> result;

		string construct;

		backtrack(map, result, digits, construct, 0);

		return result;

	}
};

int main()
{
	Solution s;
	return 0;
}
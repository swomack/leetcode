#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	string commonSub(string a, string b)
	{
		int index = 0;
		string result;

		while (index < a.length() && index < b.length())
		{
			if (a[index] != b[index])
				break;

			result += a[index];
			index++;
		}

		return result;
	}

	string longestCommonPrefix(vector<string>& strs) 
	{
		string result;
		if (strs.size() == 0)
			return result;

		if (strs.size() == 1)
			return strs[0];

		result = strs[0];

		for (int i = 1; i < strs.size(); i++)
		{
			if (result.length() == 0)
				break;

			result = commonSub(result, strs[i]);
		}

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}
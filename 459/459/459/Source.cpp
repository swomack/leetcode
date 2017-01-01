#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool repeatedSubstringPattern(string str) {
		if (str.length() <= 1)
			return false;

		int pattern_index = 0;
		int run = 1;
		bool ret = true;
		while (run < str.length())
		{
			int start = run;
			for (int i = 0; run - start <= pattern_index; run++, i++)
			{
				if (str[run] == str[i])
				{
					ret = true;
					continue;
				}
					

				pattern_index = start;
				run = pattern_index + 1;
				ret = false;
				break;
			}
		}
		
		return ret;
	}
};

int main()
{
	Solution s;
	bool res = s.repeatedSubstringPattern("abacababacab");
	return 0;
}
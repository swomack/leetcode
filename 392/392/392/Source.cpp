#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	bool isSubsequence(string s, string t) 
	{
		int s_s = s.length();
		int s_t = t.length();

		for (int i = s_t - 1; i >= 0; i--)
		{
			if (t[i] == s[s_s - 1])
				s_s--;

			if (!s_s)
				break;
		}

		return s_s == 0;
	}
};

int main()
{
	Solution s;
	bool res = s.isSubsequence("abc", "aghbfgc");
	return 0;
}
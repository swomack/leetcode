#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	bool isIsomorphic(string s, string t) 
	{
		bool result = true;

		unordered_map<char, char> map_s;
		unordered_map<char, char> map_t;

		for (int i = 0; i < s.length(); i++)
		{
			int val_t = map_t[t[i]];
			int val_s = map_s[s[i]];
			if (val_t == 0 && val_s == 0)
			{
				map_t[t[i]] = s[i];
				map_s[s[i]] = t[i];
			}
			else if(val_t != s[i] || val_s != t[i])
			{
				result = false;
				break;
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	bool res = s.isIsomorphic("egg", "aba");
	return 0;
}

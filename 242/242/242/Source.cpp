#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool isAnagram(string s, string t) 
	{
		if (s.length() != t.length())
			return false;

		vector<int> frequency_s(26);
		vector<int> frequency_t(26);

		for (int i = 0; i < s.length(); i++)
		{
			frequency_s[s[i] - 97]++;
			frequency_t[t[i] - 97]++;
		}

		return equal(frequency_s.begin(), frequency_s.end(), frequency_t.begin()) ? true : false;
	}
};


int main()
{
	Solution s;
	bool result = s.isAnagram("anagram", "aggaram");
	return 0;
}
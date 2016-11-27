#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
	bool isAnagram(string s, string t) 
	{
		if (s.length() != t.length())
			return false;

		unordered_map<char, int> map;

		for_each(s.begin(), s.end(), [&map](char element) {
			map[element]++;
		});

		bool result = true;

		find_if(t.begin(), t.end(), [&map, &result](char element) {
			if (map[element])
			{
				map[element] --;
				return false;
			}

			result = false;
			return true;
		});

		return result;
	}
};


int main()
{
	Solution s;
	bool result = s.isAnagram("anagram", "aggaram");
	return 0;
}
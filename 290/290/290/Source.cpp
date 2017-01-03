#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) 
	{
		vector<string> map(26);
		unordered_map<string, char> rev_map;
		int index = 0;
		char* pch = strtok((char*)str.c_str(), " ");
		while (pch && index < pattern.length())
		{
			if (map[pattern[index] - 'a'].length() == 0)
			{
				if (rev_map[pch] != 0)
					return false;

				map[pattern[index] - 'a'] = pch;
				rev_map[pch] = pattern[index];
			}
			else
			{
				
				if (map[pattern[index] - 'a'] != pch || rev_map[pch] != pattern[index])
					return false;
			}

			pch = strtok(NULL, " ");
			index++;		
		}

		return pch == NULL && index >= pattern.length();
	}
};

int main()
{
	Solution s;
	bool res = s.wordPattern("abba", "dog cat cat dog");
	return 0;
}
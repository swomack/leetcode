#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<int> findAnagrams(string s, string p) 
	{
		vector<int> result;

		if (p.length() > s.length())
			return result;

		vector<int> map(26);

		for_each(p.begin(), p.end(), [&map](char element) {
			map[element - 'a']++;
		});

		vector<int> running_map(26);
		int length = p.length();

		for (int i = 0, j = 0; j < s.length(); j++)
		{
			int val_r = s[j] - 'a';
			int val_l = s[i] - 'a';

			if (map[val_r] == 0)
			{
				memset(&running_map[0], 0, running_map.size() * sizeof running_map[0]);
				i = j + 1;
				continue;
			}


			running_map[val_r]++;

			if (running_map[val_r] > map[val_r])
			{
				while (s[i] != s[j])
				{
					running_map[s[i] - 'a']--;
					i++;
				}

				running_map[s[i] - 'a']--;
				i++;
			}
			else if(j - i == length - 1)
			{
				result.push_back(i);
				running_map[val_l]--;
				i++;
			}
		}
		

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> res = s.findAnagrams("cbaebabacd",
		"abc");
	return 0;
}
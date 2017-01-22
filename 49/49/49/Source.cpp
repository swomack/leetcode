#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	bool check_equal(vector<int>& a, vector<int>& b)
	{
		for (int i = 0; i < 26; i++)
		{
			if (a[i] != b[i])
				return false;
		}

		return true;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		vector<vector<string>> result;
		vector<pair<int, vector<int>>> group_map;

		for (int i = 0; i < strs.size(); i++)
		{
			vector<int> map(26);

			for (int j = 0; j < strs[i].length(); j++)
				map[strs[i][j] - 'a']++;

			bool found = false;
			for (int j = 0; j < group_map.size(); j++)
			{
				if (group_map[j].first != strs[i].length())
					continue;
				bool equal = check_equal(group_map[j].second, map);

				if (equal)
				{
					found = true;
					result[j].push_back(strs[i]);
					break;
				}
			}

			if (!found)
			{
				result.resize(result.size() + 1);
				result[result.size() - 1].push_back(strs[i]);
				group_map.push_back(make_pair(strs[i].length(), map));
			}
				
		}

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}
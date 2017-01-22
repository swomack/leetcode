#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		vector<vector<string>> result;
		unordered_map<string, int> group_map;

		for (int i = 0; i < strs.size(); i++)
		{
			string cpy = strs[i];
			sort(strs[i].begin(), strs[i].end());

			int index = group_map[strs[i]];

			if (index)
			{
				result[index - 1].push_back(cpy);
			}
			else
			{
				vector<string> list;
				list.push_back(cpy);
				result.push_back(list);
				group_map[strs[i]] = result.size();
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
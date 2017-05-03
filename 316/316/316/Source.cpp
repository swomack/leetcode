#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	string removeDuplicateLetters(string s) 
	{
		vector<int> map(26, 0);
		
		for_each(s.begin(), s.end(), [&map](char x) {
			map[x - 'a'] ++;
		});

		string result;
		vector<bool> obsolate(26, false);

		for (int i = 0; i < s.length(); i++)
		{
			if (obsolate[s[i] - 'a'])
				continue;

			if (result.empty())
			{
				result.push_back(s[i]);
				continue;
			}


			if (map[s[i] - 'a'] == 1)
			{
				char top = result[result.size() - 1];
				while (!result.empty() && map[top - 'a'] != 1 && s[i] <= top)
				{
					map[top - 'a']--;
					result.pop_back();
					if (!result.empty())
						top = result[result.size() - 1];
				}

				if (result.empty())
				{
					result.push_back(s[i]);
				}
				else
				{
					obsolate[top - 'a'] = true;
					result.push_back(s[i]);
				}
			}
			else
			{
				char top = result[result.size() - 1];

				while (!result.empty() && map[top - 'a'] != 1 && s[i] <= top)
				{
					map[top - 'a']--;
					result.pop_back();

					if(!result.empty())
						top = result[result.size() - 1];
				}

				if (result.empty())
				{
					result.push_back(s[i]);
				}
				else 
				{
					if(map[s[i] - 'a'] == 1)
						obsolate[top - 'a'] = true;
					result.push_back(s[i]);
				}
			}
		}


		return result;
	}
};


int main()
{
	Solution s;

	string res = s.removeDuplicateLetters("bbbacacca");

	return 0;
}
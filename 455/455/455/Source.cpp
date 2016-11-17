#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int findContentChildren(vector<int>& g, vector<int>& s) 
	{
		if (s.size() == 0)
			return 0;

		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

		if (s[s.size() - 1] < g[0])
			return 0;

		int content = 0;

		for (int i = 0; i < s.size() && content < g.size(); i++)
		{
			if (s[i] >= g[content])
			{
				content++;
			}
		}

		return content;
	}
};

int main()
{
	Solution s;

	vector<int> param1;
	vector<int> param2;

	param1.push_back(10);
	param1.push_back(9);
	param1.push_back(8);
	param1.push_back(7);
	param1.push_back(10);
	param1.push_back(9);
	param1.push_back(8);
	param1.push_back(7);

	param2.push_back(10);
	param2.push_back(9);
	param2.push_back(8);
	param2.push_back(7);

	int children = s.findContentChildren(param1, param2);

	getchar();
}
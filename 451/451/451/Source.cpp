#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Solution 
{
public:
	string frequencySort(string s) 
	{
		vector<int> map(256);

		int length = s.length();

		for (int i = 0; i < length; i++)
			map[s[i]]++;

		priority_queue<pair<int, int>> pq;

		for (int i = 0; i < 256; i++)
		{
			if (map[i])
				pq.push(make_pair(map[i], i));
		}

		string res;

		while (!pq.empty())
		{
			pair<int, int> top = pq.top();
			pq.pop();

			while (top.first--)
				res.push_back(top.second);
		}

		return res;
	}
};

int main()
{
	Solution s;

	string res = s.frequencySort("tree");

	return 0;
}

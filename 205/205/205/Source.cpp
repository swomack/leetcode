#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct comp
{
	bool operator () (vector<int>& lhs, vector<int>& rhs)
	{
		if (lhs.size() == 0 && rhs.size() == 0)
			return true;
		else if (lhs.size() > rhs.size())
			return true;
		else if (lhs[0] > rhs[0])
			return true;

		return false;
	}
};

class Solution 
{
public:

	bool isEqual(vector<int>& a, vector<int>& b)
	{
		if (a.size() != b.size())
			return false;

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] != b[i])
				return false;
		}

		return true;
	}

	bool isIsomorphic(string s, string t) 
	{
		vector<vector<int>> count1(256);
		vector<vector<int>> count2(256);

		int index = 0;

		for_each(s.begin(), s.end(), [&count1, &index](char element) {
			count1[element].push_back(index++);
		});

		index = 0;
		for_each(t.begin(), t.end(), [&count2, &index](char element) {
			count2[element].push_back(index++);
		});

		sort(count1.begin(), count1.end());
		sort(count2.begin(), count2.end());

		bool result = true;

		for (int i = 255; i >= 0; i--)
		{
			if (count1[i].size() == 0 && count2[i].size() == 0)
				break;

			if (isEqual(count1[i], count2[i]))
				continue;

			result = false;
			break;
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

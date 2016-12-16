#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	struct zero
	{
		bool operator () (pair<int, int> a, pair<int, int> b)
		{
			return a.first < b.first;
		}
	};

	struct one
	{
		bool operator () (pair<int, int> a, pair<int, int> b)
		{
			return a.second < b.second;
		}
	};

	int findMaxForm(vector<string>& strs, int m, int n) 
	{
		vector<pair<int, int>> counts;

		for (int i = 0; i < strs.size(); i++)
		{
			int z = 0;
			int o = 0;

			for (int j = 0; j < strs[i].length(); j++)
			{
				if (strs[i][j] == '0')
					z++;
				else
					o++;
			}


			counts.push_back(make_pair(z, o));
		}


		// sort based on zero
		sort(counts.begin(), counts.end(), zero());

		int count_1 = 0;

		int z_count = 0;
		int o_count = 0;

		for (int i = 0; i < counts.size(); i++)
		{
			z_count += counts[i].first;
			o_count += counts[i].second;

			if (z_count <= m && o_count <= n)
				count_1++;
			else
				break;
		}

		// sort based on one
		sort(counts.begin(), counts.end(), one());

		int count_2 = 0;

		z_count = 0;
		o_count = 0;

		for (int i = 0; i < counts.size(); i++)
		{
			z_count += counts[i].first;
			o_count += counts[i].second;

			if (z_count <= m && o_count <= n)
				count_2++;
			else
				break;
		}

		return max(count_1, count_2);
	}
};

int main()
{
	Solution s;
	return 0;
}
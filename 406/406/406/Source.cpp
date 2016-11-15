#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;


class Solution 
{
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) 
	{
		list<pair<int, int>> result;
		
		// sort by the height descending order
		sort(people.begin(), people.end(), [](pair<int, int> &a, pair<int, int> &b) {
			if (a.first > b.first)
				return true;
			else if (a.first == b.first && a.second < b.second)
				return true;

			return false;
		});

		// use list to insert, faster than using vector directly
		for_each(people.begin(), people.end(), [&result] (pair<int, int>& element) {
			list<pair<int, int>>::iterator it = result.begin();
			int i = element.second;
			while (i--)
			{
				it++;
			}
			result.insert(it, element);

		});

		vector<pair<int, int>> res;

		for (list<pair<int, int>>::iterator it = result.begin(); it != result.end(); it++)
		{
			res.push_back(*(it));
		}


		return res;
	}
};

int main()
{
	Solution s;

	vector<pair<int, int>> param;
	param.push_back(make_pair(7, 0));
	param.push_back(make_pair(4, 4));
	param.push_back(make_pair(7, 1));
	param.push_back(make_pair(5, 0));
	param.push_back(make_pair(6, 1));
	param.push_back(make_pair(5, 2));

	vector<pair<int, int>> result = s.reconstructQueue(param);

	getchar();
}
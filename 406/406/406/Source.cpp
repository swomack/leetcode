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
		
		sort(people.begin(), people.end(), [](pair<int, int> &a, pair<int, int> &b) {
			if (a.second < b.second)
				return true;
			else if (a.second == b.second && a.first < b.first)
				return true;

			return false;
		});


		for_each(people.begin(), people.end(), [&result] (pair<int, int>& element) {
			list<pair<int, int>>::iterator it = result.begin();
			int kk = element.second;
			for (; it != result.end(); it++)
			{
				pair<int, int> a = (*it);

				if (element.first > a.first)
					continue;

				element.second--;
			}
		});

		vector<pair<int, int>> res;
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
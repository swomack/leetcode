#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct cmpStruct {
	bool operator() (int const & lhs, int const & rhs) const
	{
		return lhs > rhs;
	}
};

class Solution 
{
public:
	int thirdMax(vector<int>& nums) 
	{
		set<int, cmpStruct> cont;

		for_each(nums.begin(), nums.end(), [&cont](int element) {
			cont.insert(element);
		});

		if (cont.size() < 3)
			return *(cont.begin());

		cont.erase(cont.begin());
		cont.erase(cont.begin());

		return *(cont.begin());
	}
};

int main()
{
	Solution s;
	vector<int> param{ 1,2,2,3,3 };
	int res = s.thirdMax(param);
	return 0;
}
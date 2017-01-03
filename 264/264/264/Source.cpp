#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <set>

using namespace std;

class Solution 
{
public:
	int nthUglyNumber(int n) 
	{
		set<long> ugly;
		std::set<long>::iterator it;
		
		ugly.insert(1);
		while (--n)
		{
			it = ugly.begin();
			long top = (*it);
			ugly.erase(it);

			ugly.insert(2 * top);
			ugly.insert(3 * top);
			ugly.insert(5 * top);
		}

		return *(ugly.begin());
	}
};

int main()
{
	Solution s;
	return 0;
}
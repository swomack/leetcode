#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
	int nthUglyNumber(int n) 
	{
		vector<long> uglys_2;
		vector<long> uglys_3;
		vector<long> uglys_5;

		uglys_2.push_back(2);
		uglys_3.push_back(3);
		uglys_5.push_back(5);

		int i_2 = 0;
		int i_3 = 0;
		int i_5 = 0;

		int ugly = 1;

		while(--n)
		{
			ugly = min(uglys_2[i_2], min(uglys_3[i_3], uglys_5[i_5]));
			if (uglys_2[i_2] <= ugly)
				i_2++;
			if (uglys_3[i_3] <= ugly)
				i_3++;
			if (uglys_5[i_5] <= ugly)
				i_5++;

			uglys_2.push_back(2 * ugly);
			uglys_3.push_back(3 * ugly);
			uglys_5.push_back(5 * ugly);
		}

		return ugly;
	}
};

int main()
{
	Solution s;
	return 0;
}
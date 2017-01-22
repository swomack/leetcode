#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int hIndex(vector<int>& citations) 
	{
		sort(citations.begin(), citations.end());

		int count = citations.size();
		int res = 0;
		for (int i = count - 1; i >= 0; i--)
		{
			if (citations[i] >= (count - i))
			{
				res ++;
			}
			else
			{
				break;
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	return 0;
}
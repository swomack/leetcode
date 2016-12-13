#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int maxProfit(vector<int>& prices) 
	{
		if (prices.size() <= 1)
			return 0;

		int min_index = 0;
		int max_index = 0;
		int profit = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] < prices[min_index])
			{
				if(max_index > min_index)
					profit += (prices[max_index] - prices[min_index]);

				min_index = max_index = i;
				continue;
			}
			else if (prices[i] >= prices[max_index])
			{
				max_index = i;
				continue;
			}
			else
			{
				profit += (prices[max_index] - prices[min_index]);
				max_index = min_index = i;
			}
		}

		if(max_index == prices.size() - 1)
			profit += (prices[max_index] - prices[min_index]);

		return profit;
	}
};

int main()
{
	Solution s;
	return 0;
}
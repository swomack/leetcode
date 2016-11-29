#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	int maxProfit(vector<int>& prices) 
	{
		int output = 0;
		int highest = -1;

		// scanning from the end
		// we wont by before local maaxima and sell after it 
		// we will check the every biggest output for each local maxima
		for (int i = prices.size() - 1; i >= 0; i--)
		{
			output = max(output, highest - prices[i]);

			// if it is highest then we wont sell after it if we buy before it
			highest = max(highest, prices[i]);
		}

		return output;
	}
};


int main()
{
	return 0;
}
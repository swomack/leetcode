#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class Solution 
{
public:
	int nthUglyNumber(int n) 
	{
		priority_queue<long, vector<long>, greater<long>> queue;
		queue.push(1);
		long last_element = -1;
		while (true)
		{
			long top = queue.top();
			queue.pop();
			if (last_element == top)
				continue;
			last_element = top;
			n--;

			if (n == 0)
				break;

			queue.push(2 * top);
			queue.push(3 * top);
			queue.push(5 * top);
		}

		return last_element;
	}
};

int main()
{
	Solution s;
	return 0;
}
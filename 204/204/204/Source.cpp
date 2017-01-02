#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int countPrimes(int n) 
	{
		if (n <= 2)
			return 0;

		vector<bool> map(n);

		for (int i = 3; i * i < n; i+=2)
		{
			if (map[i])
				continue;

			for (int j = i * i; j < n; j += i)
				map[j] = true;
		}

		int count = 1;
		for (int i = 3; i < n; i += 2)
		{
			if (!map[i])
				count++;
		}

		return count;
	}
};

int main()
{
	Solution s;
	int count = s.countPrimes(10000);
	return 0;
}
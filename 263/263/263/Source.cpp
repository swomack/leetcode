#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool isUgly(int num) 
	{
		if (num <= 0)
			return false;
		if (num < 7)
			return true;

		vector<int> primes{ 2, 3, 5 };

		for (int i = 0; i < primes.size(); i++)
		{
			int prime = primes[i];
			while (num > 1 && num % prime == 0)
				num /= prime;
		}


		return num < 7;
	}
};

int main()
{
	getchar();
	return 0;
}
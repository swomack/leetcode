#include <iostream>

using namespace std;

class Solution 
{
public:

	long long int binomialCooeficient(int n, int k) // nCk = n! / (n - k)! * k!
	{
		long long int result = 1;

		k = (n - k) > k ? k : (n - k);

		for (int i = 0; i < k; i++)  // n! / (n - k)! * k! = n * (n - 1) * (n - 2) * .... (n - (k - 1)) / k!
		{
			result *= (n - i); //n * (n - 1) ... there are k terms in here
			result /= (i + 1); // divided by k!, we are dividing by one at a time starting from 1 to k
		}

		return result;
	}

	// catalan(n) = (1 / (n + 1)) * binomial_cooef (2n and n)
	int calculateCatalan(int n)
	{
		return binomialCooeficient(2 * n, n) / (n + 1);
	}

	int numTrees(int n) 
	{
		return calculateCatalan(n);
	}
};

int main()
{
	Solution s;
	int res = s.numTrees(19);
	return 0;
}
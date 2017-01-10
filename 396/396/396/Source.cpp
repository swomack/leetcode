#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int maxRotateFunction(vector<int>& A) 
	{
		long long sum = 0;
		long long f = 0;
		long long n = (long long) A.size();
		for (long long i = 0; i < n; i++)
		{
			sum += (long long)A[i];
			f += ((long long) A[i] * i);
		}

		long long max_f = f;

		for (long long i = n - 1; i >= 0; i--)
		{
			long long new_f = f - (long long)A[i] * (n - 1) + (sum - (long long)A[i]);
			max_f = max(max_f, new_f);
			f = new_f;
		}

		return max_f;
	}
};

int main()
{
	Solution s;
	return 0;
}
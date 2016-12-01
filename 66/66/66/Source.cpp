#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<int> plusOne(vector<int>& digits) 
	{
		int n = digits.size();

		while (--n >= 0 && digits[n] == 9)
		{
			digits[n] = 0;
		}

		if (n < 0)
			digits.insert(digits.begin(), 1);
		else
			digits[n] += 1;

		return digits;
		
	}
};


int main()
{
	Solution s;
	vector<int> param{ 1, 0 };
	vector<int> res = s.plusOne(param);
	return 0;
}
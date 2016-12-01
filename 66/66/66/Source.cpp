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

		if (digits[0] == 9 && digits[n - 1] == 9)
		{
			vector<int> result;
			--n;
			while (n >= 0 && digits[n] == 9)
			{
				result.push_back(0);
				n--;
			}

			result.push_back(digits[n] + 1);
			n--;

			while (n >= 0)
			{
				result.push_back(digits[n]);
			}
				

			reverse(result.begin(), result.end());
			return result;
		}
		else
		{
			vector<int> result(n);
			n--;
			while (n >= 0 && digits[n] == 9)
			{
				result[n] = 0;
				--n;
			}

			result[n] = digits[n] + 1;
			n--;
			while (n >= 0)
			{
				result[n] = digits[n];
				n--;
			}
			
			return result;
		}
		
	}
};


int main()
{
	Solution s;
	vector<int> param{ 1, 0 };
	vector<int> res = s.plusOne(param);
	return 0;
}
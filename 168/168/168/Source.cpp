#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) 
	{
		string result;

		while (n)
		{
			n--;
			int k = n % 26;

			result.push_back('A' + k);
			n /= 26;
		}

		reverse(result.rbegin(), result.rend());
		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}

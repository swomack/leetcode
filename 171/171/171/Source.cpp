#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int titleToNumber(string s) 
	{
		int result = 0;
		transform(s.begin(), s.end(), s.begin(), ::tolower);

		int index = 1;
		for_each(s.rbegin(), s.rend(), [&index, &result](char element) {
			int val = element - 96;
			val *= index;
			result += val;
			index *= 26;
		});

		return result;
	}
};


int main()
{
	Solution s;

	int number = s.titleToNumber("AAB");

	getchar();

	return 0;
}

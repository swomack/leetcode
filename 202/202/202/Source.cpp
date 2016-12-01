#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool isHappy(int n) 
	{
		unordered_map<int, int> map;

		map[n] = 1;

		while (n != 1)
		{
			int new_number = 0;
			while (n)
			{
				int remainder = n % 10;
				n /= 10;
				new_number += (remainder * remainder);
			}

			n = new_number;

			if (map[n] > 0 || n == 4)
				break;

			map[n] = 1;
		}

		return n == 1;
	}
};


int main()
{
	Solution s;
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:

	string trim(string& str, char trim)
	{
		size_t first = str.find_first_not_of(trim);

		if(first == string::npos)
			return str.substr(0, 0);

		size_t last = str.find_last_not_of(trim);

		return str.substr(first, last - first + 1);
	}


	int myAtoi(string str) 
	{
		if (str.length() <= 0)
			return 0;

		int ind = 0;

		while (ind < str.length() && str[ind] == ' ')
			ind++;

		if (ind >= str.length())
			return 0;
	
		long res = 0;
		long mult = 1;
		if (str[ind] == '-')
		{
			mult = -1;
			ind++;
		}
		else if (str[ind] == '+')
		{
			ind++;
		}
			
		
		for (; ind < str.length(); ind++)
		{
			if (str[ind] >= '0' && str[ind] <= '9')
			{
				res *= 10;
				res += long(str[ind] - '0');

				if (res * mult > INT_MAX)
					return INT_MAX;

				if (res * mult < INT_MIN)
					return INT_MIN;

				continue;
			}
				
			break;
		}

		return res * mult;
	}
};

int main()
{
	Solution s;
	int val = s.myAtoi("9223372036854775809");
	return 0;
}
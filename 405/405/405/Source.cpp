#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution 
{
public:

	vector<char> map;
	vector<char> reverse_map;

	Solution()
	{
		for (int i = 0; i < 10; i++)
			map.push_back('0' + i);

		for (int i = 0; i <= 6; i++)
			map.push_back('a' + i);

		for (int i = 0; i < 6; i++)
			reverse_map.push_back('f' - i);

		for (int i = 0; i < 10; i++)
			reverse_map.push_back('9' - i);
	}

	string toHex(int num) 
	{
		if (num == 0)
			return "0";

		if (num == INT_MIN)
			return "80000000";

		string str;
		
		if (num > 0)
			getHex(str, num);
		else
			getNegHex(str, abs(num));

		reverse(str.rbegin(), str.rend());

		return str;

	}

	void getHex(string& s, int num)
	{
		while(num)
		{
			s.push_back(map[num % 16]);
			num /= 16;
		}
	}

	void getNegHex(string& s,int num)
	{
		while (num)
		{
			s.push_back(reverse_map[num%16]);
			num /= 16;
		}

		addOne(s);

		for (int i = s.length(); i < 8; i++)
			s.push_back('f');
	}

	void addOne(string& num)
	{
		int carry = 1;
		int i = 0;
		while (carry)
		{
			int digit = toDec(num[i]);
			digit++;

			num[i++] = map[digit % 16];
			carry = digit / 16;
		}
	}

	int toDec(char digit)
	{
		if (digit >= '0' && digit <= '9')
			return digit - '0';

		return digit - 'a' + 10;
	}
};

int main()
{
	Solution s;
	string res = s.toHex(-26);
	return 0;
}
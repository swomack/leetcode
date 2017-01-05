#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:

	string trim(string& str, char trim)
	{
		size_t first = str.find_first_not_of(trim);
		size_t last = str.find_last_not_of(trim);

		return str.substr(first, last - first + 1);
	}

	string trimFirst(string& str, char trim)
	{
		size_t first = str.find_first_not_of(trim);

		if (first == string::npos)
			return str.substr(0, 0);

		return str.substr(first);
	}

	string trimLast(string& str, char trim)
	{
		size_t last = str.find(trim);


		return str.substr(0, last);
	}

	long convert(string& s)
	{
		long num = 0;

		for (int i = 0; i < s.size(); i++)
		{
			num *= 10;
			num += s[i] - '0';
		}

		return num;
	}

	int myAtoi(string str) 
	{
		string s = trimFirst(str, '-');

		int mult = 1;
		if (str.length() != s.length())
			mult = -1;

		s = trimFirst(s, '+');

		s = trimFirst(s, '0');
		s = trimLast(s, '.');

		return mult * convert(s);
	}
};

int main()
{
	Solution s;
	int val = s.myAtoi("0");
	return 0;
}
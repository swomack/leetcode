#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	string trim(string s)
	{
		size_t first = s.find_first_not_of(' ');

		if (first == string::npos)
			return s;

		size_t last = s.find_last_not_of(' ');
		return s.substr(first, last - first + 1);
	}
	int lengthOfLastWord(string s) 
	{

		string trimmed = trim(s);
		
		for (int i = trimmed.length() - 1; i >= 0; i--)
		{
			if (trimmed[i] == ' ')
				return trimmed.length() - i - 1;
		}

		return trimmed.length();
	}
};

int main()
{
	Solution s;
	return 0;
}
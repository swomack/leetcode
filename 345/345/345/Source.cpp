#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:

	bool isVowel(char c)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;

		if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
			return true;

		return false;
	}

	string reverseVowels(string s) 
	{
		int first = 0;
		int second = s.length() - 1;

		while (first < second)
		{
			if (!isVowel(s[first]))
				first++;

			if (!isVowel(s[second]))
				second--;

			if (isVowel(s[first]) && isVowel(s[second]))
			{
				char temp = s[first];
				s[first] = s[second];
				s[second] = temp;

				first++;
				second--;
			}
			
		}

		return s;
	}
};

int main()
{
	Solution s;
	string res = s.reverseVowels("hello");
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	int strStr(string haystack, string needle) 
	{
		int check = haystack.length() - needle.length() + 1;
		for (int i = 0; i < check; i++)
		{
			bool found = true;
			for (int j = 0; j < needle.length(); j++)
			{
				if (needle[j] != haystack[i + j])
				{
					found = false;
					break;
				}	
			}

			if (found)
				return i;
		}

		return -1;
	}
};

int main()
{
	Solution s;
	int index = s.strStr("abb", "abaaa");
	return 0;
}
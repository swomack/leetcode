#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int countSegments(string s) 
	{
		int last_space = -1;
		int count = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
			{
				if (i - last_space > 1)
					count++;
				last_space = i;
			}
		}

		if (s.length() - last_space > 1)
			count++;

		return count;
	}
};

int main()
{
	return 0;
}
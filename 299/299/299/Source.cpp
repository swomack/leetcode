#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	string getHint(string secret, string guess) 
	{
		int b = 0;
		int c = 0;
		vector<int> count_s(10);
		vector<int> count_g(10);
		int length = secret.length();
		for (int i = 0; i < length; i++)
		{
			if (secret[i] == guess[i])
				b++;
			else
			{
				count_s[secret[i] - '0']++;
				count_g[guess[i] - '0']++;
			}
				
		}
			
	
		for (int i = 0; i < 10; i++)
		{
			c += min(count_s[i], count_g[i]);
		}

		return to_string(b) + "A" + to_string(c) + "B";
	}
};

int main()
{
	Solution s;
	return 0;
}
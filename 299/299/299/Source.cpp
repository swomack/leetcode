#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
	string getHint(string secret, string guess) 
	{
		int b = 0;
		int c = 0;
		vector<int> count;
		for (int i = 0; i < secret.length(); i++)
		{
			if (secret[i] == guess[i])
				b++;
			else
				count[secret[i]]++;
		}
			
	
		for (int i = 0; i < guess.length(); i++)
		{
			if (count[guess[i]] == 0 || guess[i] == secret[i])
				continue;

			c++;
			count[guess[i]]--;
		}

		return to_string(b) + "A" + to_string(c) + "B";
	}
};

int main()
{
	Solution s;
	return 0;
}
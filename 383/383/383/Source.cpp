#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool canConstruct(string ransomNote, string magazine) 
	{
		vector<int> map(256);

		int mag_length = magazine.length();

		for (int i = 0; i < mag_length; i++)
		{
			map[magazine[i]]++;
		}

		int ran_length = ransomNote.length();

		for (int i = 0; i < ran_length; i++)
		{
			if (map[ransomNote[i]] <= 0)
				return false;

			map[ransomNote[i]]--;
		}

		return true;
	}
};

int main()
{
	Solution s;
	return 0;
}
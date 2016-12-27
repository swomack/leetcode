#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	string originalDigits(string s) 
	{
		vector<int> map(26);

		for (int i = 0; i < s.length(); i++)
		{
			map[s[i] - 'a']++;
		}

		vector<int> result(9);

		result[0] = map['z' - 'a'];
		result[2] = map['w' - 'a'];
		result[4] = map['u' - 'a'];
		result[6] = map['x' - 'a'];
		result[8] = map['g' - 'a'];

		result[1] = map['o' - 'a'] - result[0] - result[2] - result[4];
		result[3] = map['h' - 'a'] - result[8];
		result[5] = map['f' - 'a'] - result[4];
		result[7] = map['v' - 'a'] - result[5];
		result[9] = (map['n' - 'a'] - result[1] - result[7]) / 2;

		string res;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < result[i]; j++)
				res.push_back('0' + i);
		}

		return res;
	}
};

int main()
{
	Solution s;
	string res = s.originalDigits("xis");
	return 0;
}
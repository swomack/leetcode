#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution 
{
public:

	void append_string(unsigned int number, vector<string>& result, vector<char>& map)
	{
		string str(10, 0);

		unsigned int mask = 3;

		for (int i = 0; i < 10; i++)
		{
			str[9 - i] = map[number & mask];
			number >>= 2;
		}

		result.push_back(str);
	}

	vector<string> findRepeatedDnaSequences(string s) 
	{
		vector<string> result;

		if (s.size() < 11)
			return result;

		unordered_map<char, int> char_map;
		unordered_map<unsigned int, int> pos_map;
		char_map['A'] = 0;
		char_map['C'] = 1;
		char_map['G'] = 2;
		char_map['T'] = 3;

		vector<char> reverse_map{ 'A', 'C', 'G', 'T' };

		int number = 0;
		int index = 0;

		while (index < 10)
		{
			number <<= 2;
			number |= char_map[s[index++]];
		}

		pos_map[number] = index - 1;

		unsigned int mask = ~(4293918720);

		while (index < s.length())
		{
			number <<= 2;
			number &= mask;
			number |= char_map[s[index]];

			if (pos_map[number] > 0)
			{
				append_string(number, result, reverse_map);
				pos_map[number] = -1;
			}
			else if (pos_map[number] != -1)
			{
				pos_map[number] = index;
			}

			index++;
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<string> res = s.findRepeatedDnaSequences("GAGAGAGAGAGA");
	return 0;
}
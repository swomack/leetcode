#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution 
{
public:
	vector<string> findRepeatedDnaSequences(string s) 
	{
		vector<string> result;
		unsigned int mask = ~(4293918720), number = 0, index = 0;
		unordered_map<unsigned int, int> pos_map;
		unordered_map<char, int> char_map;
		char_map['A'] = 0; char_map['C'] = 1; char_map['G'] = 2; char_map['T'] = 3;

		while (index < 10 && index < s.length())
			number = (number << 2) | char_map[s[index++]];
		
		pos_map[number] = 1;

		while (index < s.length())
		{
			number  = (number << 2) & mask | char_map[s[index++]];
			
			if (pos_map[number]++ == 1)
				result.push_back(s.substr(index - 10, 10));
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
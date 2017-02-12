#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	vector<string> findWords(vector<string>& words) 
	{
		vector<string> result;

		vector<string> layout{"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};

		for_each(words.begin(), words.end(), [&result, &layout](string element) {
			if (element.length() <= 0)
				return;

			string copy = element;

			std::transform(element.begin(), element.end(), element.begin(), ::toupper);

			int pos = ((layout[0].find(element[0]) != string::npos) ? 0 : ((layout[1].find(element[0]) != string::npos) ? 1 : (layout[2].find(element[0]) != string::npos) ? 2 : -1));

			if (pos == -1)
				return;

			for (int i = 1; i < element.length(); i++)
			{
				if (layout[pos].find(element[i]) == string::npos)
					return;
			}

			result.push_back(copy);
		});

		return result;
	}
};

int main()
{
	Solution s;
	return 0;
}

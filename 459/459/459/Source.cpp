#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	bool repeatedSubstringPattern(string str) {
		if (str.length() <= 1)
			return false;

		string pattern;
		string matche;

		vector<string> matches;

		bool ret = true;

		for (int i = 0; i < str.length(); i++)
		{
			if (pattern.length() <= 0)
			{
				pattern.push_back(str[i]);
				continue;
			}
			
			if (matche.length() <= 0)
			{
				matche.push_back(str[i]);
				continue;
			}

			if (matche.length() == pattern.length())
			{
				if (matche == pattern)
				{
					ret = true;

					matches.push_back(matche);
					matche = "";
					matche.push_back(str[i]);
				}
				else
				{
					for (int j = 0; j < matches.size(); j++)
						pattern += matches[j];

					matches.clear();
					pattern += matche;
					matche = "";
					matche.push_back(str[i]);
					ret = false;
				}
				continue;
			}

			bool cont = true;
			for (int j = 0; j < matche.length(); j++)
			{
				if (matche[j] != pattern[j])
				{
					cont = false;
					break;
				}
			}

			if (cont)
			{
				matche.push_back(str[i]);

				if (matche == pattern)
				{
					ret = true;

					matches.push_back(matche);
					matche = "";
				}
				else
				{
					ret = false;
				}
			}
			else
			{
				for (int j = 0; j < matches.size(); j++)
					pattern += matches[j];

				matches.clear();
				pattern += matche;
				matche = "";
				matche.push_back(str[i]);
				ret = false;
			}
		}

		return ret || (matche.length() > 0 ? matche == pattern : true);
	}
};

int main()
{
	Solution s;
	bool res = s.repeatedSubstringPattern("abacababacab");
	return 0;
}
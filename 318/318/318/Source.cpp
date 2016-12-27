#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int maxProduct(vector<string>& words) 
	{
		int max_product = 0;

		int words_length = words.size();
		vector<vector<int>> maps(words_length);

		for (int i = 0; i < words_length; i++)
		{
			maps[i].resize(26);

			int word_length = words[i].length();

			for (int j = 0; j < word_length; j++)
			{
				maps[i][words[i][j] - 97]++;
			}
		}

		for (int i = 0; i < words_length - 1; i++)
		{
			string word1 = words[i];
			for (int j = i + 1; j < words_length; j++)
			{
				string word2 = words[j];

				// check distinct
				bool distinct = true;
				for (int k = 0; k < word2.length(); k++)
				{
					if (maps[i][word2[k] - 97])
					{
						distinct = false;
						break;
					}
				}

				if (distinct)
				{
					int product_length = word1.length() * word2.length();
					max_product = max(max_product, product_length);
				}
			}
		}

		return max_product;
	}
};


int main()
{
	Solution s;
	return 0;
}
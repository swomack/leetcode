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

		vector<int> value_map(words_length);

		for (int i = 0; i < words_length; i++)
		{
			string word = words[i];
			int word_length = word.length();
			for (int j = 0; j < word_length; j++)
				value_map[i] |= (1 << (word[j] - 'a'));
		}

		for (int i = 0; i < words_length - 1; i++)
		{
			for (int j = i + 1; j < words_length; j++)
			{
				// check distinct
				if (!(value_map[i] & value_map[j]))
				{
					int product_length = words[i].length() * words[j].length();
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
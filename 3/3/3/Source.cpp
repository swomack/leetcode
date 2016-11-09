#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class Solution 
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		vector<char> check_vec;
		

		int index = 0;
		int longest = 0;
	
		for_each(s.begin(), s.end(), [&index, &longest, &check_vec](char& c) {
			check_vec.push_back(c);

			vector<bool> hash(250);
			fill(hash.begin(), hash.end(), false);
			int cur_lngst = 0;
			for (int i = check_vec.size() - 1; i >= 0; i--)
			{
				if (hash[check_vec[i]])
					break;
				hash[check_vec[i]] = true;
				cur_lngst++;
			}

			longest = max(longest, cur_lngst);

			index++;
		});

		
		return longest;
	}
};

int main()
{
	Solution s;
	int ans = s.lengthOfLongestSubstring("c");
	cout << ans << endl;
	ans = s.lengthOfLongestSubstring("bbbb");
	cout << ans << endl;
	ans = s.lengthOfLongestSubstring("pwwkew");
	cout << ans << endl;
	getchar();
	return 0;
}
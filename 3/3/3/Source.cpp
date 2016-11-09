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
		vector<int> last_duplicate_pos(128);
		fill(last_duplicate_pos.begin(), last_duplicate_pos.end(), -1);
		

		int index = 0;
		int longest = 0;
		int running_dup = 0;
	
		for_each(s.begin(), s.end(), [&index, &longest, &running_dup, &last_duplicate_pos](char& c) {

			if (last_duplicate_pos[c] != -1 && last_duplicate_pos[c] >= running_dup)
			{
				longest = max(longest, index - running_dup);
				running_dup = last_duplicate_pos[c] + 1;
			}
			
			last_duplicate_pos[c] = index;

			index++;
		});

		longest = max(longest, index - running_dup);

		
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
	ans = s.lengthOfLongestSubstring("abcabcbb");
	cout << ans << endl;
	getchar();
	return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
public:

	int next_sol;

	unordered_map<string, string> url_map;

	Solution()
	{
		next_sol = 0;
		url_map.clear();
	}

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) 
	{
		string s = to_string(next_sol++);
		url_map[s] = longUrl;
		return s;

	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) 
	{
		return url_map[shortUrl];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main()
{
	return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Twitter
{
public:

	int post_serial;

	unordered_map<int, vector<pair<int, int>>> user_posts;
	unordered_map<int, vector<int>> followees;

	/** Initialize your data structure here. */
	Twitter() 
	{
		post_serial = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) 
	{
		pair<int, int> post(++post_serial, tweetId);
		user_posts[userId].push_back(post);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) 
	{
		vector<int> result;
		followees[userId].push_back(userId);

		vector<int> indices(followees[userId].size(), 1);

		while (result.size() < 10)
		{
			pair<int, int> latest_post(make_pair(-1, - 1));
			int latest_index = -1;
			for (int i = 0; i < followees[userId].size(); i++)
			{
				int index = user_posts[followees[userId][i]].size() - indices[i];
				if (index < user_posts[followees[userId][i]].size() && user_posts[followees[userId][i]][index].first > latest_post.first)
				{
					latest_index = i;
					latest_post = user_posts[followees[userId][i]][index];
				}
			}

			if (latest_index == -1)
				break;

			result.push_back(latest_post.second);
			indices[latest_index]++;
		}
		

		followees[userId].pop_back();

		return result;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) 
	{
		if (followerId == followeeId)
			return;

		vector<int>::iterator it = find(followees[followerId].begin(), followees[followerId].end(), followeeId);

		if (it != followees[followerId].end())
			return;

		followees[followerId].push_back(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) 
	{
		vector<int>::iterator it = find(followees[followerId].begin(), followees[followerId].end(), followeeId);

		if (it == followees[followerId].end())
			return;

		followees[followerId].erase(it);
	}
};

int main()
{
	Twitter t;

	t.postTweet(1, 5);
	t.postTweet(1, 3);

	vector<int> a = t.getNewsFeed(1);

	return 0;
}
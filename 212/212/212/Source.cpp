#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {

public:
	struct TrieNode
	{
		vector<TrieNode*> nodes;
		bool isLeaf;
		int count;

		TrieNode()
		{
			nodes.resize(26);
			memset(&nodes[0], 0, 26 * sizeof(size_t));
			isLeaf = false;
			count = 0;
		}
	};


	TrieNode* root;

	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {

		TrieNode* current_node = root;

		for (int i = 0; i < word.length(); i++)
		{
			if (current_node->nodes[word[i] - 'a'] == NULL)
				current_node->nodes[word[i] - 'a'] = new TrieNode();

			current_node = current_node->nodes[word[i] - 'a'];
			current_node->count++;
		}

		current_node->isLeaf = true;
	}
};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
	{
		Trie* t = new Trie();

		for (int i = 0; i < words.size(); i++)
			t->insert(words[i]);

		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));


		const int row = board.size();
		const int col = board[0].size();

		vector<string> result;
		string res;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (t->root->nodes[board[i][j] - 'a'] != NULL && t->root->nodes[board[i][j] - 'a']->count > 0)
				{
					visited[i][j] = true;
					res.push_back(board[i][j]);

					t->root->nodes[board[i][j] - 'a']->count -= findWords(board, i, j, t->root->nodes[board[i][j] - 'a'], res, result, visited);

					res.pop_back();
					visited[i][j] = false;

					if (result.size() == words.size())
						return result;
				}
			}
		}

		return result;
	}

	int findWords(vector<vector<char>>& board, int i, int j, Trie::TrieNode* node, string& res, vector<string>& result, vector<vector<bool>> visited)
	{
		int count = 0;

		if (node->isLeaf)
		{
			result.push_back(res);
			node->isLeaf = false;
			count++;
		}

		if (i > 0 && visited[i - 1][j] == false && node->nodes[board[i - 1][j] - 'a'] != NULL && node->nodes[board[i - 1][j] - 'a']->count > 0)
		{
			visited[i - 1][j] = true;
			res.push_back(board[i - 1][j]);
			int c = findWords(board, i - 1, j, node->nodes[board[i - 1][j] - 'a'], res, result, visited);
			count += c;
			node->nodes[board[i - 1][j] - 'a']->count -= c;
			res.pop_back();
			visited[i - 1][j] = false;
		}

		if (j > 0 && visited[i][j - 1] == false && node->nodes[board[i][j - 1] - 'a'] != NULL && node->nodes[board[i][j - 1] - 'a']->count > 0)
		{
			visited[i][j - 1] = true;
			res.push_back(board[i][j - 1]);
			int c = findWords(board, i, j - 1, node->nodes[board[i][j - 1] - 'a'], res, result, visited);
			count += c;
			node->nodes[board[i][j - 1] - 'a']->count -= c;
			res.pop_back();
			visited[i][j - 1] = false;
		}

		if (i < board.size() - 1 && visited[i + 1][j] == false && node->nodes[board[i + 1][j] - 'a'] != NULL && node->nodes[board[i + 1][j] - 'a']->count > 0)
		{
			visited[i + 1][j] = true;
			res.push_back(board[i + 1][j]);
			int c = findWords(board, i + 1, j, node->nodes[board[i + 1][j] - 'a'], res, result, visited);
			count += c;
			node->nodes[board[i + 1][j] - 'a']->count -= c;
			res.pop_back();
			visited[i + 1][j] = false;
		}

		if (j < board[0].size() - 1 && visited[i][j + 1] == false && node->nodes[board[i][j + 1] - 'a'] != NULL && node->nodes[board[i][j + 1] - 'a']->count > 0)
		{
			visited[i][j + 1] = true;
			res.push_back(board[i][j + 1]);
			int c = findWords(board, i, j + 1, node->nodes[board[i][j + 1] - 'a'], res, result, visited);
			count += c;
			node->nodes[board[i][j + 1] - 'a']->count -= c;
			res.pop_back();
			visited[i][j + 1] = false;
		}

		return count;

	}
};

int main()
{
	Solution s;
	return 0;
}
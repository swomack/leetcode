#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Trie {
protected:
	struct TrieNode
	{
		vector<TrieNode*> nodes;
		bool isLeaf;

		TrieNode()
		{
			nodes.resize(26);
			memset(&nodes[0], 0, 26 * sizeof(size_t));
			isLeaf = false;
		}
	};


	TrieNode* root;

public:
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
		}

		current_node->isLeaf = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) 
	{
		TrieNode* current_node = root;

		for (int i = 0; i < word.length(); i++)
		{
			if (current_node->nodes[word[i] - 'a'] == NULL)
				return false;

			current_node = current_node->nodes[word[i] - 'a'];
		}

		return current_node->isLeaf;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) 
	{
		TrieNode* current_node = root;

		for (int i = 0; i < prefix.length(); i++)
		{
			if (current_node->nodes[prefix[i] - 'a'] == NULL)
				return false;

			current_node = current_node->nodes[prefix[i] - 'a'];
		}

		return true;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/

int main()
{
	Trie* t = new Trie();
	t->insert("a");
	bool res = t->search("a");
	res = t->startsWith("a");
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class WordDictionary {
protected:
	static const int NODE_CHILD_LENGTH = 26;
	struct TrieNode
	{
		vector<TrieNode*> nodes;
		bool isLeaf;

		TrieNode()
		{
			nodes.resize(NODE_CHILD_LENGTH);
			memset(&nodes[0], 0, 26 * sizeof(size_t));
			isLeaf = false;
		}
	};


	TrieNode* root;

public:
	/** Initialize your data structure here. */
	WordDictionary() 
	{
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void addWord(string word) 
	{

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
		return searchHelper(root, word, 0);
	}

	bool searchHelper(TrieNode* node, string& word, int index)
	{
		if (node == NULL)
			return false;

		if (index >= word.length())
			return node->isLeaf;

		if (word[index] == '.')
		{
			for (int i = 0; i < NODE_CHILD_LENGTH; i++)
			{
				if (searchHelper(node->nodes[i], word, index + 1))
					return true;
			}

			return false;
		}
		else
		{
			return searchHelper(node->nodes[word[index] - 'a'], word, index + 1);
		}
	}
};

int main()
{
	WordDictionary* dict = new WordDictionary();
	dict->addWord("bad");
	dict->addWord("dad");
	dict->addWord("mad");

	bool res = dict->search(".ad");

	return 0;
}
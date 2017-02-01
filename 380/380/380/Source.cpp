#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;


class RandomizedSet 
{
public:

	vector<int> elements;
	unordered_map<int, int> position;

	/** Initialize your data structure here. */
	RandomizedSet() 
	{
		
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) 
	{
		unordered_map<int, int>::iterator it = position.find(val);

		if (it != position.end())
			return false;
		
		elements.push_back(val);
		position[val] = elements.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) 
	{

		unordered_map<int, int>::iterator it = position.find(val);

		if (it == position.end())
			return false;

		int pos = it->second;
		position.erase(it);

		if (pos != elements.size() - 1)
		{
			elements[pos] = elements[elements.size() - 1];
			position[elements[pos]] = pos;
		}
		
		elements.resize(elements.size() - 1);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() 
	{
		return elements[rand() % elements.size()];
	}
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/

int main()
{
	// Init an empty set.
	RandomizedSet randomSet;

	// Inserts 1 to the set. Returns true as 1 was inserted successfully.

	randomSet.insert(0);

	// Returns false as 2 does not exist in the set.
	randomSet.remove(0);

	// Inserts 2 to the set, returns true. Set now contains [1,2].
	randomSet.insert(-1);

	// Returns false as 2 does not exist in the set.
	randomSet.remove(0);

	// getRandom should return either 1 or 2 randomly.
	randomSet.getRandom();

	// Since 2 is the only number in the set, getRandom always return 2.
	randomSet.getRandom();
	return 0;
}
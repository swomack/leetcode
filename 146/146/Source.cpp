#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache 
{
private:
	int capacity;
	vector<int> lastUsedVector;
	int lastUsedPositionInVector;
	unordered_map<int, int> keyPosInVector;
	unordered_map<int, int> keyValueMap;

public:
	LRUCache(int _capacity) 
	{

	}

	int get(int _key) 
	{

	}

	void put(int _key, int _value) 
	{

	}
};

int main()
{
	return 0;
}
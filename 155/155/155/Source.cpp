#include <iostream>
#include <vector>


using namespace std;

class MinStack {
	vector<int> actual;
	vector<int>min_stack;
public:
	/** initialize your data structure here. */
	MinStack() {
		
	}

	void push(int x) {
		actual.push_back(x);

		if (min_stack.empty() || min_stack[min_stack.size() - 1] >= x)
			min_stack.push_back(x);
	}

	void pop() {
		if (!min_stack.empty() && min_stack[min_stack.size() - 1] == actual[actual.size() - 1])
			min_stack.pop_back();

		actual.pop_back();
	}

	int top() {
		return actual[actual.size() - 1];
	}

	int getMin() {
		return min_stack[min_stack.size() - 1];
	}
};

int main()
{
	return 0;
}
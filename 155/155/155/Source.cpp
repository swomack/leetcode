#include <iostream>
#include <stack>

using namespace std;

class MinStack {
	stack<int> actual;
	stack<int>min_stack;
public:
	/** initialize your data structure here. */
	MinStack() {
		
	}

	void push(int x) {
		actual.push(x);

		if (min_stack.empty() || min_stack.top() >= x)
			min_stack.push(x);
	}

	void pop() {

		int rem = actual.top();
		actual.pop();

		if (!min_stack.empty() && min_stack.top() == rem)
			min_stack.pop();
	}

	int top() {
		return actual.top();
	}

	int getMin() {
		return min_stack.top();
	}
};

int main()
{
	return 0;
}
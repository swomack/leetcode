#include <iostream>

using namespace std;

int guess(int num)
{
	if (num == 1702766719)
		return 0;
	if(num > 1702766719)
		return -1;
	if (num < 1702766719)
		return 1;
}

class Solution 
{
public:
	int guessNumber(int n) 
	{
		int low = 1;
		int high = n;

		int middle = 0;
		
		while (true)
		{
			middle = (low + high) / 2;
			int feedback = guess(middle);

			switch (feedback)
			{
			case 0:
				return middle;
			case -1:
				high = middle - 1;
				break;
			case 1:
				low = middle + 1;
				break;
			}
		}

		return middle;
	}
};

int main()
{
	Solution s;

	int result = s.guessNumber(2126753390);

	return 0;
}
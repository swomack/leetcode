#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution 
{
public:

	int intersected_area(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		if (A > G || C < E)
			return 0;

		if (B > H || D < F)
			return 0;

		return abs(max(E, A) - min(C, G)) * abs(max(B, F) - min(D, H));
	}

	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
	{
		int width1 = abs(C - A);
		int height1 = abs(D - B);

		int width2 = abs(G - E);
		int height2 = abs(H - F);

		int total_area = width1 * height1 + width2 * height2;

		return total_area - intersected_area(A, B, C, D, E, F, G, H);
	}
};

int main()
{
	Solution s;
	int res = s.computeArea(0, 0, 0, 0, -1, -1, 1, 1);
	return 0;
}
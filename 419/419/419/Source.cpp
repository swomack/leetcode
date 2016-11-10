#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int countBattleships(vector<vector<char>>& board) 
	{
		int height, width;

		height = board.size();
		width = board[0].size();

		int total_count = 0;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				//// alternate solution
				//if (board[i][j] == '.')
				//{
				//	if (i > 0  && board[i - 1][j] == 'X')
				//	{
				//		total_count++;
				//		board[i - 1][j] = '-';
				//	}

				//	if (j > 0 && board[i][j - 1] == 'X')
				//	{
				//		total_count++;
				//		board[i][j - 1] = '-';
				//	}
				//}
				//else if (i == height - 1 && j == width - 1)
				//{
				//	total_count++;
				//}
				
		
				if (board[i][j] == '-')
					continue;


				if (board[i][j] == '.')
					continue;

				board[i][j] = '-';

				

				if (j < width - 1 && board[i][j + 1] == 'X')
				{
					for (int k = 1; j + k < width; k++)
					{
						char b_char = board[i][j + k];
						board[i][j + k] = '-';
						if (b_char != 'X')
							break;
					}
				}
				else if (i < height - 1 && board[i + 1][j] == 'X')
				{
					

					for (int k = 1; i + k < height; k++)
					{
						char b_char = board[i + k][j];
						board[i + k][j] = '-';
						if (b_char != 'X')
							break;
					}
				}
		
				total_count++;
			}
		}

		return total_count;
	}
};

int main()
{
	Solution s;

	vector<vector<char>> src_vector;

	/*vector<char> a1 = { 'X', '.', '.', 'X' };
	vector<char> a2 = { '.', '.', '.', 'X' };
	vector<char> a3 = { '.', '.', '.', 'X' };
	vector<char> a4 = { '.', '.', '.', 'X' };*/

	vector<char> a1 = { 'X', '.', 'X' };

	src_vector.push_back(a1);
	/*src_vector.push_back(a2);
	src_vector.push_back(a3);
	src_vector.push_back(a4);*/

	int total_type = s.countBattleships(src_vector);

	cout << total_type << endl;

	getchar();
	
}
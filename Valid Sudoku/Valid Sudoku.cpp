#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	 void solveSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		int x = 0, y = 0;

		hGetNextCell(board, x, y);
		vector<int> lvCandidate = hGetCandidate4Cell(board, x, y);

		for(int i = 0; i< lvCandidate.size(); i ++)
		{
			board[x][y] = lvCandidate[i] + '0';
			if(hSolveSudoku(board, x, y))
			{
				break;
			}
			board[x][y] = '.';
		}
    }
	 bool hSolveSudoku(vector<vector<char> >& board, int x, int y)
	 {
		hGetNextCell(board, x, y);

		if(x == 9 && y == 9)
			return true;

		vector<int> lvCandidate = hGetCandidate4Cell(board, x, y);

		for(int i = 0; i< lvCandidate.size(); i ++)
		{
			board[x][y] = lvCandidate[i] + '0';
			if(hSolveSudoku(board, x, y))
			{
				return true;
			}
			board[x][y] = '.';
		}

		return false;
	 }
	 vector<int> hGetCandidate4Cell(vector<vector<char> > &board, int x, int y)
		{
			bool lb[9];
			memset(lb, 0, sizeof(bool) * 9);

			for(int i = 0; i< 9; i ++)
				if(board[x][i] != '.')
					lb[board[x][i] - '0' - 1] = true;

			for(int i = 0; i< 9; i ++)
				if(board[i][y] != '.')
					lb[board[i][y] - '0' - 1] = true;

			int startX = 0;
			while(startX <= x)
			{
				startX += 3;
			}
			startX -= 3;

			int startY = 0;
			while(startY <= y)
				startY += 3;
			startY -= 3;
			for(int i = startX; i< startX + 3; i++)
				for(int j = startY; j < startY + 3; j++)
					if(board[i][j] != '.')
						lb[board[i][j] - '0' - 1] = true;
			
			vector<int> lvResult;
			for(int i = 0; i< 9; i++)
				if(lb[i] == false)
					lvResult.push_back(i + 1);

			return lvResult;

		}

		void hGetNextCell(vector<vector<char> > &board, int& x, int& y)
		{
			for(; x < 9; x ++)
			{
				if(y == 9)
					y = 0;
				for(; y < 9; y ++)
				{
					if(board[x][y] == '.')
						return;
				}
			}
		}

    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		bool lb[10];
		for(int i = 0; i< 9; i ++)
		{
			memset(lb, 0, sizeof(bool)* 10);
			for(int j = 0; j< 9; j++)
			{
				if(board[i][j] != '.')
				{
					int a = board[i][j] - '0';
					if(lb[a] == false)
						lb[a] = true;
					else
						return false;
				}
			}
		}
		
		for(int i = 0; i< 9; i ++)
		{
			memset(lb, 0, sizeof(bool)* 10);
			for(int j = 0; j< 9; j++)
			{
				if(board[j][i] != '.')
				{
					int a = board[j][i] - '0';
					if(lb[a] == false)
						lb[a] = true;
					else
						return false;
				}
			}
		}

		for(int starti = 0; starti< 9; starti+= 3)
		{
			for(int startj = 0; startj< 9; startj += 3)
			{
				memset(lb, 0, sizeof(bool)* 10);
				for(int i = starti; i< starti + 3; i++)
				{
					for(int j = startj; j<startj +  3; j++)
					{
						if(board[i][j] != '.')
						{
							int a = board[i][j] - '0';
							if(lb[a] == false)
								lb[a] = true;
							else
								return false;
						}
					}
				}
			}
		}

		return true;

    }
};

int main()
{
	char* a[] = {"..9748...",
				 "7........",
				 ".2.1.9...",
				 "..7...24.",
				 ".64.1.59.",
				 ".98...3..",
				 "...8.3.2.",
				 "........6",
				 "...2759.."};
	vector<vector<char> > board;
	for(int i = 0; i< 9; i++)
	{	board.push_back(vector<char>(a[i], a[i] + 9));
	}
	Solution mS;
	bool result = mS.isValidSudoku(board);
	mS.solveSudoku(board);
	return 0;
}
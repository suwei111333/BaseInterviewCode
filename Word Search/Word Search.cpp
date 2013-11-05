#include <iostream>
#include <vector>
#include <string>
using namespace std;


int xAction[] = {0, 0, 1, -1};
int yAction[] = {1, -1, 0, 0};

class Solution {
public:

	bool hExist(vector<vector<char> >& irboard, int x, int y, string& irword, int iIndex,
				vector<vector<int> >& irvvVisited)
	{
		if(iIndex >= irword.length())
			return true;
		int len = irboard.size();
		int width = irboard[0].size();
		for(int i = 0; i < 4; i++)
		{
			int tmpX = x + xAction[i];
			int tmpY = y + yAction[i];
			if(tmpX >=0 && tmpX < len && tmpY >= 0 && tmpY < width 
				&& irvvVisited[tmpX][tmpY] == 0&& irboard[tmpX][tmpY] == irword[iIndex])
			{
				irvvVisited[tmpX][tmpY] = 1;
				if(hExist(irboard, tmpX, tmpY, irword, iIndex + 1, irvvVisited))
				{
					return true;
				}
				irvvVisited[tmpX][tmpY] = 0;
			}
		}
		return false;
	}

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(word.empty()) return true;
		if(board.empty()) return false;
		
		int len = board.size();
		int width = board[0].size();
	
		vector<vector<int> > lvvbVisited(len, vector<int>(width, 0)); 
		for(int i = 0; i< len; i++)
		{
			for(int j = 0; j< width;j++)
			{
				if(board[i][j] == word[0])
				{
					lvvbVisited[i][j] = 1;
					if(hExist(board, i, j, word, 1, lvvbVisited))
						return true;
					lvvbVisited[i][j] = 0;
				}
			}
		}
		return false;
    }
};

int main()
{
	Solution mS;
	
	string a[] = {"ABCE", "SFCS", "ADEE"};
	vector<vector<char> > board;
	board.push_back(vector<char>(a[0].begin(), a[0].end()));
	board.push_back(vector<char>(a[1].begin(), a[1].end()));
	board.push_back(vector<char>(a[2].begin(), a[2].end()));

	string target;
	while(cin >> target)
	{
		bool lb = mS.exist(board, target);
		int i = 1;
	}
	return 0;
}


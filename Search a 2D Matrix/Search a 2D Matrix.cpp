#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	//time cost: m + n
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if(matrix.empty()) return false;
		if(matrix[0].empty()) return false;

		int lnRows = matrix.size();
		int lnColumn = matrix[0].size();

		int X = 0;
		int Y = lnColumn -1;
		while(X < lnRows && Y >= 0)
		{
			if(matrix[X][Y] == target)
				return true;
			
			if(matrix[X][Y] < target)
				X ++;
			else
				Y --;
		}
		return false;
	}

	//step1. binary search to find the RowIndex, ln(m)
	//step2. binary search to find the ColumnIndex in this row, ln(n)
	//time cost: ln(m) + ln(n)
    bool searchMatrix2(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(matrix.empty()) return false;
		if(matrix[0].empty()) return false;

		int lnRows = matrix.size();
		int lnColumns = matrix[0].size();

		int RowIndex = 0;
		int L = 0, H = lnRows-1;
		while(L < H)
		{
			int M = L + (H -L)/2;
			
			if(matrix[M][lnColumns - 1] == target)
				return true;
			if(matrix[M][lnColumns - 1] < target)
				L = M + 1;
			else
				H = M;
		}

		RowIndex = L;
		L = 0;
		H = lnColumns - 1;
		while(L <= H)
		{
			int M = L + (H - L)/2;
			if(matrix[RowIndex][M] == target)
				return true;
			if(matrix[RowIndex][M] < target)
				L = M + 1;
			else
				H = M - 1;
		}
		return false;
    }
};

int main()
{
	Solution mS;
	
	int a[] = {1, 3,5, 7};
	int b[] = {10,11,16, 20};
	int c[] = {23, 30, 34, 50};
	vector<vector<int> > matrix;
	matrix.push_back(vector<int>(a, a+ sizeof(a)/sizeof(int)));
	matrix.push_back(vector<int>(b, b+ sizeof(b)/sizeof(int)));
	matrix.push_back(vector<int>(c, c+ sizeof(c)/sizeof(int)));
	mS.searchMatrix(matrix, 23);
	return 0;
}
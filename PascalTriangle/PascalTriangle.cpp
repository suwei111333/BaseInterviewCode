#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > PascalTriangle;
		if(numRows <=0)
			return PascalTriangle;

		PascalTriangle.resize(numRows);

		for(int i = 0; i< numRows; i++)
		{
			int column = i + 1;
			PascalTriangle[i].resize(column);
			for(int j = 0; j< column; j ++)
			{
				if(j == 0 || j == column -1)
				{
					PascalTriangle[i][j] = 1;
				}
				else
					PascalTriangle[i][j] = PascalTriangle[i -1][j -1] + PascalTriangle[i - 1][j];
			}
		}

		return PascalTriangle;
    }

	vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		rowIndex ++;
		vector<int> PascalTriangleRow;
		if(rowIndex <= 0) return PascalTriangleRow;

		PascalTriangleRow.resize(rowIndex);
		for(int i = 0; i< rowIndex; i++)
		{
			int column = i + 1;
			for(int j = column -1; j >= 0; j --)
			{
				if(j == 0 || j == column -1)
				{
					PascalTriangleRow[j] = 1;
				}
				else
					PascalTriangleRow[j] = PascalTriangleRow[j] + PascalTriangleRow[j -1];
			}
		}
		return PascalTriangleRow;

        
    }
};

int main()
{
	int n;
	while(cin >> n)
	{
		Solution mSolution;
		mSolution.generate(n);
		mSolution.getRow(n);
	}
	return 0;
}
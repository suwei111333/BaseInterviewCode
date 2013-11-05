#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n == 0) return vector<vector<int> >();
        
		vector<vector<int> > matrix(n, vector<int>(n, 0));
		
		int beginX = 0, endX = n - 1;
		int beginY = 0, endY = n - 1;
		int Index = 1;
		
		while(true)
		{
			for(int i = beginX; i <= endX; i ++)
			{
				matrix[beginY][i] = Index ++;
			}
			if(++beginY > endY) break;
				
			for(int i = beginY; i<= endY; i++)
			{
				matrix[i][endX] = Index ++;
			}
			if(beginX > --endX) break;
			
			for(int i = endX; i>= beginX; i--)
			{
				matrix[endY][i] = Index ++;
			}
			if(beginY > --endY) break;
			
			for(int i = endY; i>= beginY; i--)
			{
				matrix[i][beginX] = Index ++;
			}	
			if( ++ beginX > endX) break;
		}

		return matrix;
    }
};

class Solution1 {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(matrix.empty()) return vector<int>();
		if(matrix[0].empty()) return vector<int>();

		vector<int> result;
		int n = matrix.size();
		int m = matrix[0].size();
		int beginX = 0, endX = m - 1;
		int beginY = 0, endY = n -1;
		while(true)
		{
			for(int i = beginX; i <= endX; i ++)
			{
				result.push_back(matrix[beginY][i]);
			}
			if(++beginY > endY) break;
				
			for(int i = beginY; i<= endY; i++)
			{
				result.push_back(matrix[i][endX]);
			}
			if(beginX > --endX) break;
			
			for(int i = endX; i>= beginX; i--)
			{
				result.push_back(matrix[endY][i]);
			}
			if(beginY > --endY) break;
			
			for(int i = endY; i>= beginY; i--)
			{
				result.push_back(matrix[i][beginX]);
			}	
			if( ++ beginX > endX) break;
		}
        return result;
    }
};

int main()
{
	Solution mS1;

	mS1.generateMatrix(4);

	Solution1 mS;

	int a[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	vector<vector<int> > matrix;
	matrix.push_back(vector<int>(a[0], a[0] + 4));
	matrix.push_back(vector<int>(a[1], a[1] + 4));
	matrix.push_back(vector<int>(a[2], a[2] + 4));
	matrix.push_back(vector<int>(a[3], a[3] + 4));
	mS.spiralOrder(matrix);
	return 0;
}
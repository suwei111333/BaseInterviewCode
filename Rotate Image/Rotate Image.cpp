#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int n = matrix.size();

		for(int i = 0; i< n ; i ++)
			for(int j = i + 1; j < n; j++)
				swap(matrix[i][j], matrix[j][i]);
	
		for(int i = 0; i< n; i++)
			for(int j = 0; j < n/2; j++)
				swap(matrix[i][j], matrix[i][n - j - 1]);

    }
};


int main()
{

	int a[][3] = {{1,2,3}, 
				  {4,5,6}, 
				  {7,8,9}};
	vector<vector<int> > matrix;
	matrix.push_back(vector<int>(a[0], a[0] + 3));
	matrix.push_back(vector<int>(a[1], a[1] + 3));
	matrix.push_back(vector<int>(a[2], a[2] + 3));

	Solution mS;
	 mS.rotate(matrix);
	return 0;
}
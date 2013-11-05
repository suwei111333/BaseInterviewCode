#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;


bool isSameBST(vector<int>& irvA, vector<int>& irvB)
{
	if(irvA.size() != irvB.size())
		return false;

	if(irvA.empty() && irvB.empty())
		return true;

	if(irvA[0] != irvB[0])
		return false;

	vector<int> lvALess;
	vector<int> lvAMore;
	vector<int> lvBLess;
	vector<int> lvBMore;
	
	for(int i = 1; i< irvA.size(); i++)
	{
		if(irvA[i] > irvA[0])
			lvAMore.push_back(irvA[i]);
		else if(irvA[i] < irvA[0])
			lvALess.push_back(irvA[i]);
		else
			assert(false);
	}

	for(int i = 1; i< irvB.size(); i++)
	{
		if(irvB[i] > irvB[0])
			lvBMore.push_back(irvB[i]);
		else if(irvB[i] < irvB[0])
			lvBLess.push_back(irvB[i]);
		else
			assert(false);
	}

	return isSameBST(lvALess, lvBLess) && isSameBST(lvAMore, lvBMore);
}

int main()
{
	{
		int A[] = {2, 1, 3};
		int B[] = {2, 3, 1};
		vector<int> lvA(A, A + sizeof(A)/sizeof(int));
		vector<int> lvB(B, B + sizeof(B)/sizeof(int));
		assert(isSameBST(lvA, lvB)== true);
	}

	{
		int A[] = {1};
		int B[] = {1};
		vector<int> lvA(A, A + sizeof(A)/sizeof(int));
		vector<int> lvB(B, B + sizeof(B)/sizeof(int));
		assert(isSameBST(lvA, lvB)== true);
	}

	{
		int A[] = {1};
		int B[] = {2};
		vector<int> lvA(A, A + sizeof(A)/sizeof(int));
		vector<int> lvB(B, B + sizeof(B)/sizeof(int));
		assert(isSameBST(lvA, lvB)== false);
	}

	{
		int A[] = {1};
		int B[] = {2, 3, 1};
		vector<int> lvA(A, A + sizeof(A)/sizeof(int));
		vector<int> lvB(B, B + sizeof(B)/sizeof(int));
		assert(isSameBST(lvA, lvB)== false);
	}

	{
		int A[] = {2, 1, 3, 5, 4, 6};
		int B[] = {2, 3, 1, 4, 5, 6};
		vector<int> lvA(A, A + sizeof(A)/sizeof(int));
		vector<int> lvB(B, B + sizeof(B)/sizeof(int));
		assert(isSameBST(lvA, lvB)== false);
	}
	{
		int A[] = {2, 1, 3, 5, 4, 6};
		int B[] = {2, 3, 1, 5, 4, 6};
		vector<int> lvA(A, A + sizeof(A)/sizeof(int));
		vector<int> lvB(B, B + sizeof(B)/sizeof(int));
		assert(isSameBST(lvA, lvB)== true);
	}


	return 0;
}
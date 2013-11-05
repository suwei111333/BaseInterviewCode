#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <bitset>
#include <assert.h>
#define INT32BITSZIZE 32
#define MAXARRAY 100000
using namespace std;

int inputArray[MAXARRAY*2];

void generateInputArray(int* ipArray, int n, int& A, int& B)
{
	srand((unsigned)time(0));
	for(int i = 0; i< n/2; i++)
	{
		ipArray[i*2] = i;
		ipArray[i*2 + 1] = i;
	}
	A = rand() %(n/2);
	B = rand() %(n/2);
	while(A == B)
	{
		B = rand() %(n/2);
	}

	ipArray[A*2] = B;

	if(A > B)
	{
		swap(A, B);
	}
	//cout << A << ' ' << B << endl;
}
void printArray(int* ipArray, int n)
{
	for(int i = 0; i< n; i++)
		cout << ipArray[i] << ' ';

	cout << endl;
}

void find2OddNum(int* ipArray, int n, int& OXA, int& OXB)
{
	int OXResult = 0;
	for(int i = 0; i< n; i++)
	{
		if(i == 0)
			OXResult = ipArray[i];
		else
			OXResult ^=ipArray[i];
	}

	bitset<INT32BITSZIZE> lVS(OXResult);

	int firstPos = -1;
	for(int i = 0; i< INT32BITSZIZE; i++)
	{
		if(lVS.test(i))
		{
			firstPos = i;
			break;
		}
	}

	if(firstPos == -1)
	{
		return;
	}

	OXA = -1;
	OXB = -1;
	for(int i = 0; i< n; i++)
	{
		bitset<INT32BITSZIZE> llVS(ipArray[i]);
		if(llVS.test(firstPos))
		{
			if(OXA == -1)
				OXA = ipArray[i];
			else
				OXA ^= ipArray[i];
		}
		else
		{
			if(OXB == -1)
				OXB = ipArray[i];
			else
				OXB ^= ipArray[i];
		}
	}
	if(OXA > OXB)
		swap(OXA, OXB);

	//cout << OXA  << ' ' << OXB << endl;
}

void testCase()
{
	int AA, AB;
	generateInputArray(inputArray, MAXARRAY*2, AA, AB);
	//printArray(inputArray, MAXARRAY * 2);	

	int AR, BR;
	find2OddNum(inputArray, MAXARRAY * 2, AR, BR);

	assert(AA == AR && AB == BR);
}

int main()
{

	for(int i = 0; i< 1000; i++)
	{
		cout << i << " times" << endl;
		testCase();
	}
	int a;
	cin >> a;

	return 0;
}
#include <iostream>
using namespace std;

int MostA = 0;
void GetMostA(int N, int speed, int NumA)
{
	if(N <= 0)
	{
		MostA = max(MostA, NumA);
		return;
	}

	if(N >= 2)
	{
		GetMostA(N -2, NumA, NumA);
	}

	GetMostA(N -1, speed, NumA + speed);

	GetMostA(N -1, speed, NumA + 1);
	
}
int main()
{
	for(;;)
	{
		int inputN = 0;
		cin >> inputN;
		MostA = 0;
		GetMostA(inputN, 0, 0);

		cout << MostA << endl;
	}


	int a;
	cin >> a;
	return 0;
}
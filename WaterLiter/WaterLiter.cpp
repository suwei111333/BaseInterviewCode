#include <iostream>
#include <assert.h>
#define UNINITIALIIION -1.0
using namespace std;

double dp[10][10];
double OverFlow[10][10];
double WaterLiter = 0;

//dp[i][j] = if(1/2* OverFlow[i-1][j-1] + 1/2 * OverFlow[i - 1][j] > 1)
void GetWaterLiter(int i, int j, int iWL)
{
	if(dp[i][j] != UNINITIALIIION)
		return;
	
	if(i == 1)
	{
		assert(j == 1);
		dp[i][j] = iWL > 1.0 ? 1: iWL;
		OverFlow[i][j] = iWL >1.0 ? iWL -1.0: 0;
		return;
	}

	double leftWater = 0.0;
	double rightWater = 0.0;

	if(j -1 >= 1) // has left Water.
	{	
		GetWaterLiter(i -1, j -1, iWL);
		leftWater = OverFlow[i-1][j-1]/2;
	}
	if(j <= i -1) // has right Water.
	{	
		GetWaterLiter(i -1, j, iWL);
		rightWater = OverFlow[i-1][j]/2;
	}
		
	dp[i][j] = leftWater + rightWater > 1.0? 1: leftWater + rightWater;
	OverFlow[i][j] = leftWater + rightWater > 1.0? leftWater + rightWater - 1.0: 0.0;
}

int main()
{
	cin >> WaterLiter;
	for(int i = 0; i< 10; i++)
		for(int j = 0; j< 10; j++)
			dp[i][j] = UNINITIALIIION;

	int m, n;
	while(cin >> m >> n)
	{
		if(n > m) //invalid dp[m][n] input.
			continue;
		if(dp[m][n] == UNINITIALIIION)
			GetWaterLiter(m, n, WaterLiter);	
			
		cout << dp[m][n] << endl;
			
	}

	return 0;
}
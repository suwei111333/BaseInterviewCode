#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	/*
	Say you have an array for which the ith element is the price of a given stock on day i.
	If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
	*/
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(prices.empty())
		{
			return 0;
		}

		int Marge = 0;
		int minPrice = prices[0];
		for(int i = 0; i< prices.size(); i++)
		{
			minPrice = min(prices[i], minPrice);

			Marge = max(Marge, prices[i]-minPrice);
		}

		return Marge;
    }

	/*
	Say you have an array for which the ith element is the price of a given stock on day i.
	Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
	*/
	int maxProfit2(vector<int> &prices) {
		
		int result = 0;
		for(int i = 1; i < prices.size(); i ++)
		{
			if(prices[i -1] < prices[i])
				result += (prices[i] - prices[i -1]);
		}

		return result;
	}

	/*
	Say you have an array for which the ith element is the price of a given stock on day i.
	Design an algorithm to find the maximum profit. You may complete at most two transactions.
	*/
	int maxProfit3(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(prices.empty())
		{
			return 0;
		}

		vector<int> lvMaxProfit(prices.size());
		int CurrentMinPrices = prices[0];
		int MaxPofit = 0;
		for(int i = 0; i < prices.size(); i++)
		{
			int profit = prices[i] - CurrentMinPrices;
			if(profit > MaxPofit)
				MaxPofit = profit;

			lvMaxProfit[i] = MaxPofit;
			CurrentMinPrices = min(prices[i], CurrentMinPrices);
		}

		vector<int> lvMaxProfit2(prices.size());
		int CurrentMaxPrices = prices[prices.size() -1];
		MaxPofit = 0;
		for(int i = prices.size() - 1; i >=0; i--)
		{
			int profit = CurrentMaxPrices - prices[i];
			if(profit > MaxPofit)
				MaxPofit = profit;

			lvMaxProfit2[i] = MaxPofit;
			CurrentMaxPrices = max(CurrentMaxPrices, prices[i]);
		}

        MaxPofit = 0;
		for(int i = 0; i< prices.size(); i++)
		{
			MaxPofit = max(MaxPofit, lvMaxProfit[i] + lvMaxProfit2[i]);
		}
		return MaxPofit;
    }
};


int main()
{

	Solution mSolution;

	vector<int> input(6);
	input[0] = 1;
	input[1] = 2;
	input[2] = 3;
	input[3] = 4;
	input[4] = 4;
	input[5] = 2;

	cout << mSolution.maxProfit(input) << endl;
	cout << mSolution.maxProfit2(input) << endl;
	cout << mSolution.maxProfit3(input) << endl;

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(num1.empty() || num2.empty()) return string();

		if(num1.size() == 1 && num1[0] == '0') return num1;
		if(num2.size() == 1 && num2[0] == '0') return num2;

		int num1Len = num1.length();
		int num2Len = num2.length();

		if(num1Len < num2Len)
		{	
			num1.swap(num2);
			swap(num1Len, num2Len);
		}

		string result;
		for(int i = num2Len -1; i >= 0; i --)
		{
			string tmpResult = hMultiply(num1, num2[i]);
			tmpResult.append(num2Len - i - 1, '0');

			result = StringAdd(result, tmpResult);
		}
		return result;
    }

	string hMultiply(string num1, char a)
	{
		string result(num1.rbegin(), num1.rend());
		int num1len = num1.length();
		int chengshu = a - '0';
		int jingwei = 0;
		for(int i = 0; i< num1len; i++)
		{
			int tmp = ((result[i] - '0') * chengshu) + jingwei;
			result[i] =  tmp % 10 + '0';
			jingwei = tmp /10;
		}
		if(jingwei)
			result.append(1, (char)(jingwei + '0'));

		return string(result.rbegin(), result.rend());
	}

	string StringAdd(string num1, string num2)
	{
		string tmpNum1(num1.rbegin(), num1.rend());
		string tmpNum2(num2.rbegin(), num2.rend());
		string result;
		int jingwei = 0;
		int i=0;
		for(i = 0; i< tmpNum1.length() && i < tmpNum2.length(); i ++)
		{
			int tmp = (tmpNum1[i] - '0') + (tmpNum2[i] - '0') + jingwei;
			result.push_back(tmp%10 + '0');
			jingwei = tmp /10;
		}
		
		for(; i< tmpNum1.length(); i++)
		{
			int tmp = (tmpNum1[i] - '0') + jingwei;
			result.push_back(tmp%10 + '0');
			jingwei = tmp /10;
		}
		for(; i < tmpNum2.length(); i++)
		{
			int tmp = (tmpNum2[i] - '0') + jingwei;
			result.push_back(tmp%10 + '0');
			jingwei = tmp /10;
		}

		if(jingwei)
			result.push_back(jingwei + '0');
		return string(result.rbegin(), result.rend());
	}
};


int main()
{
	Solution mS;
	string a, b;
	while(cin >> a >> b)
	{
		cout << mS.multiply(a, b) << endl;
	}
	return 0;
}
#include <iostream>
using namespace std;


class Solution {
public:
    int divide1(int dividend, int divisor) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(divisor == 0 || dividend == 0)
			return 0;

		bool samesign = true;
		if(dividend < 0 && divisor > 0 || dividend >0 && divisor <0)
			samesign =  false;

		long long a = abs((double)dividend);
		long long b = abs((double)divisor);
		long long result = 0;
		while(a >= b)
		{
			for(int i = 1; a >= b<<i; i++)
			{
				a -= (b << i);
				result += (1 << i);
			}
			if(a >= b)
			{
				a -= b;
				result ++;
			}
		}

		return samesign? result: -result;
    }
	int divide(int dividend, int divisor) {
        long long a = abs((double)dividend);;
        long long b = abs((double)divisor);

        long long ret = 0;
        while (a >= b) {
            long long c = b;
            for (int i = 0; a >= c; ++i, c <<= 1) {
                a -= c;
                ret += 1 << i;
            }
        }

        return ((dividend^divisor)>>31) ? (-ret) : (ret);
    }
};

int main()
{
	Solution mS;
	int a = -2147483648, b = 1;
	int c = mS.divide(a, b);

	return 0;
}
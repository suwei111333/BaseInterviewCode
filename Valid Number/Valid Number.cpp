#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        enum InputType
		{
			INVALID, //0
			SPACE,   //1
			SIGN,	 //2
			DIGIT,	 //3
			DOT,	 //4
			EXPONENT,//5
			NUM_INPUTS
		};

		int transitionTable[][NUM_INPUTS] = 
		{
			-1,  0,  3,  1,  2, -1,
			-1,  8, -1,  1,  4,  5,
			-1, -1, -1,  4, -1, -1,
			-1, -1, -1,  1,  2, -1,
			-1,  8, -1,  4, -1,  5,
			-1, -1,  6,  7, -1, -1,
			-1, -1, -1,  7, -1, -1,
			-1,  8, -1,  7, -1, -1,
			-1,  8, -1, -1, -1, -1
		};

		int state = 0;
		while(*s != '\0')
		{
			InputType inputType = INVALID;
			if(isspace(*s))
				inputType = SPACE;
			else if(*s == '+' || *s == '-')
				inputType = SIGN;
			else if(isdigit(*s))
				inputType = DIGIT;
			else if(*s == '.')
				inputType = DOT;
			else if(*s == 'e' || *s == 'E')
				inputType = EXPONENT;

			state = transitionTable[state][inputType];

			if(state == -1)
				return false;
			else
				++s;
		}

		return state == 1 ||state == 4 || state == 7|| state ==8;

    }
};

int main()
{
	Solution mS;

	string inputS;
	while(cin >>inputS)
	{
		cout << mS.isNumber(inputS.c_str()) << endl;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
简单的说，就是s1和s2是scramble的话，那么必然存在一个在s1上的长度l1，将s1分成s11和s12两段，同样有s21和s22。
那么要么s11和s21是scramble的并且s12和s22是scramble的；
要么s11和s22是scramble的并且s12和s21是scramble的。
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(s1.length() != s2.length()) return false;

		if(s1 == s2) return true;

		//减枝
		string ts1 = s1, ts2 = s2;
		sort(ts1.begin(), ts1.end());
		sort(ts2.begin(), ts2.end());
		if(ts1 != ts2) return false;

		for(int i = 1; i< s1.length(); i++)
		{
			string seg11 = s1.substr(0, i);
			string seg12 = s1.substr(i);

			{
				string seg21 = s2.substr(0, i);
				string seg22 = s2.substr(i);
				if(isScramble(seg11, seg21) && isScramble(seg12, seg22)) return true;
			}
			{
				string seg21 = s2.substr(0, s2.length() - i);
				string seg22 = s2.substr(s2.length() - i);
				if(isScramble(seg11, seg22) && isScramble(seg12, seg21)) return true;
			}
		}
		return false;
    }
};

int main()
{
	Solution mSolution;
	string s1, s2;
	while(cin >> s1 >> s2)
	{
		if(mSolution.isScramble(s1, s2))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}


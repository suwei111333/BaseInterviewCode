#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
		if(s1.length() + s2.length() != s3.length())
			return false;
		mvDP.clear();
		mvDP.resize(s1.length() + 1, vector<int>(s2.length() + 1, -1));
		return hIsInterLeave(s1, 0, s2, 0, s3);
    }

	bool hIsInterLeave(string& s1, int S1Index, string& s2, int S2Index, string& s3)
	{
		if(mvDP[S1Index][S2Index] != -1)
			return mvDP[S1Index][S2Index] == 1;

		if(S1Index == s1.length() && S2Index == s2.length() )
		{
			mvDP[S1Index][S2Index] = 1;
			return mvDP[S1Index][S2Index] == 1;
		}

		if(S1Index == s1.length())
		{
			mvDP[S1Index][S2Index] =  (s2[S2Index] == s3[S2Index + S1Index])&&hIsInterLeave(s1, S1Index, s2, S2Index + 1, s3 );
			return mvDP[S1Index][S2Index] == 1;
		}

		if(S2Index == s2.length())
		{
			mvDP[S1Index][S2Index] =  (s1[S1Index] == s3[S1Index + S2Index]) && hIsInterLeave(s1, S1Index + 1, s2, S2Index, s3);
			return mvDP[S1Index][S2Index] == 1;
		}

		if(s1[S1Index] == s3[S1Index + S2Index] && hIsInterLeave(s1, S1Index + 1, s2, S2Index, s3))
		{
			mvDP[S1Index][S2Index] = 1;
			return mvDP[S1Index][S2Index] == 1;
		}
		
		if(s2[S2Index] == s3[S1Index + S2Index] && hIsInterLeave(s1, S1Index, s2, S2Index + 1, s3))
		{
			mvDP[S1Index][S2Index] = 1;
			return mvDP[S1Index][S2Index] == 1;
		}
		
		mvDP[S1Index][S2Index] = 0;
		return mvDP[S1Index][S2Index] == 1;
	}

	vector<vector<int> > mvDP;

	
};

int main()
{
	Solution mSolution;

	string s1("a");
	string s2("");
	string s3("c");
	bool lb = mSolution.isInterleave(s1, s2, s3);
	return 0;
}
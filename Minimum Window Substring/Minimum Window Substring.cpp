#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(T.empty()) return T;
		if(S.length() < T.length()) return string();

		vector<int> needToFind(256, 0);
		vector<int> hasFound(256, 0);
		
		int Tlen = T.length();
		for(int i = 0; i< Tlen; i++)
			needToFind[T[i]] ++;

		int Slen = S.length();
		int count = 0;
		int minBegin = 0; 
		int minEnd = Slen - 1;
		int begin, end;
		bool lbfind = false;
		for(begin = 0, end = 0; end < Slen; end ++)
		{
			if(needToFind[S[end]] == 0) continue;
			hasFound[S[end]] ++;
			if(hasFound[S[end]] <= needToFind[S[end]])
				count ++;

			if(count == Tlen)
			{
				while((needToFind[S[begin]] == 0 || needToFind[S[begin]] < hasFound[S[begin]]))
				{
					if(hasFound[S[begin]] > needToFind[S[begin]])
					{	
						hasFound[S[begin]] --;
					}
					begin ++;
				}

				int windowLen = end - begin;
				if(windowLen <= minEnd - minBegin)
				{
					minEnd= end;
					minBegin = begin;
					lbfind = true;
				}
			}
		}

		return lbfind ? S.substr(minBegin, minEnd - minBegin + 1): string();
    }
};


int main()
{
	Solution mS;

	string S("a");
	string T("a");
	string result = mS.minWindow(S, T);
	return 0;
}
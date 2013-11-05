#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.size(), n = L.size(), len = L[0].size();
        map<string, int> ids;

        vector<int> need(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!ids.count(L[i])) ids[L[i]] = i;
            need[ids[L[i]]]++;
        }

        vector<int> s;
		s.resize(m, -1);
        for (int i = 0; i < m - len + 1; ++i) {
            string key = S.substr(i, len);
            s[i] = ids.count(key) ? ids[key] : -1;
        }

        vector<int> ret;
        for (int offset = 0; offset < len; ++offset) {
            vector<int> found(n, 0);
            int count = 0, begin = offset;
            for (int i = offset; i < m - len + 1; i += len) {
                if (s[i] < 0) {
                    // recount
                    begin = i + len;
                    count = 0;
                    found.clear();
                    found.resize(n, 0);
                } else {
                    int id = s[i];
                    found[id]++;
                    if (need[id] && found[id] <= need[id])
                        count++;

                    if (count == n)
                        ret.push_back(begin);

                    // move current window
                    if ((i - begin) / len + 1 == n) {
                        id = s[begin];
                        if (need[id] && found[id] == need[id])
                            count--;
                        found[id]--;
                        begin += len;
                    }
                }
            }
        }
        return ret;
    }
};


class Solution1 {
public:

	vector<int> findSubstring(string S, vector<string> &L)
	{
		if(L.empty()) return vector<int>();
		
		int numL = L.size();
		int LStrLen = L[0].length();
		
		vector<int> lvNeeds;
		vector<int> lvPos;
		vector<int> lvColor;
		{
			map<string, int> lmNeed;
			for(int i = 0; i < numL; i++)
				if(lmNeed.find(L[i]) != lmNeed.end())
					lmNeed[L[i]] ++;
				else
					lmNeed[L[i]] = 1;


			
			map<int, int> lmPos;
			map<string, int>::iterator lSIiter = lmNeed.begin();
			for(int i = 0; lSIiter != lmNeed.end(); lSIiter ++, i++)
			{
				int offset = 0;
				while(true)
				{
					offset = S.find(lSIiter->first, offset);
					if(offset == -1)
						break;
					
					lmPos[offset] = i;
					offset ++;
				}
				lvNeeds.push_back(lSIiter->second);
			}
			
			
			for(map<int, int>::iterator iter = lmPos.begin(); iter != lmPos.end(); iter ++)
			{	
				lvPos.push_back(iter->first);
				lvColor.push_back(iter->second);
			}
		}

		vector<int> result;
		result.reserve(100);
		int lnPos = lvPos.size();
		int* lvFlagCount = new int[lvNeeds.size()];
		memset(lvFlagCount, 0, sizeof(int) * numL);
		int Count = 0;
		int start = 0;
		for(int i = 0; i< lnPos; i++)
		{	
			if(i != 0)
			{
				if(lvPos[i] - lvPos[i - 1] >  LStrLen)
				{	//failed case
					start = i;
					Count = 0;
					memset(lvFlagCount, 0, sizeof(int)* numL);
				}
				else if(lvPos[i] - lvPos[i - 1] <  LStrLen)
					continue;
			}

			if(lvFlagCount[lvColor[i]] < lvNeeds[lvColor[i]])
			{
				lvFlagCount[lvColor[i]] ++;
				Count ++;
				if(Count == numL)
				{	//success case
					result.push_back(lvPos[start]);
					Count = 0;
					i = start;
					start ++;
					memset(lvFlagCount, 0, sizeof(int)* numL);
				}
			}
			else
			{	//fail case
				start = i;
				Count = 0;
				i --;
				memset(lvFlagCount, 0, sizeof(int) * numL);

			}


		}
		
		return result;

	}

    vector<int> findSubstring1(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		if(L.empty()) return vector<int>();

		vector<int> result;
		sort(L.begin(), L.end());
		do
		{
			string tmpString;
			for(int i = 0; i< L.size(); i ++)
				tmpString += L[i];

			int offset = 0;
			while(true)
			{
				offset = S.find(tmpString, offset);
				if(offset == -1)
					break;
				result.push_back(offset);
				offset ++;
			}
		}
		while(std::next_permutation(L.begin(), L.end()));
		

		return result;
    }
};

int main()
{

	string S("abaababbaba");
	char* LL[] = {"ba", "ab", "ab"};
	vector<string> L;
	for(int i = 0; i< sizeof(LL)/sizeof(char*); i++)
		L.push_back(string(LL[i]));


	Solution mS;
	
	vector<int> result = mS.findSubstring(S, L);

	
	return 0;
}
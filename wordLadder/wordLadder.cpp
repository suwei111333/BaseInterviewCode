#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<string> lStringQueue;
		queue<int> lLevelQueue;
		set<string> lVisited;
		int len = start.length();
		dict.insert(end);
		
		lStringQueue.push(start);
		lLevelQueue.push(1);
		lVisited.insert(start);
		while(!lStringQueue.empty())
		{
			string lCurString = lStringQueue.front();
			int lCurLevel = lLevelQueue.front();
			lStringQueue.pop();
			lLevelQueue.pop();

			if(end == lCurString)
			{
				return lCurLevel;
			}

			for(int i = 0; i< len; i++)
			{
				for(int j = 0; j < 26; j ++)
				{
					string ltmpString = lCurString;
					if('a' + j == lCurString[i]) continue;
					ltmpString[i] = 'a' + j;

					if(dict.find(ltmpString) != dict.end() && lVisited.find(ltmpString) == lVisited.end())
					{
						lStringQueue.push(ltmpString);
						lLevelQueue.push(lCurLevel + 1);
						lVisited.insert(ltmpString);
					}
				}
			}
		}
		return 0;
    }

	void hfindLadders(string& start, string& end, map<string, bool>& imVisited, vector<string>& irvResult, 
		int level, vector<vector<string>>& iorvvFinalResult)
	{
		if(start == end)
		{
			iorvvFinalResult.push_back(vector<string>(irvResult.begin(), irvResult.begin() + level + 1));
			return;
		}

		int len = start.length();
		for(int i = 0; i< len; i++)
		{
			string ltempString = start;
			for(int j = 0; j < 26; j ++)
			{
				if('a' + j == ltempString[i]) continue;
				ltempString[i] = 'a' + j;
				map<string, bool>::iterator iter = imVisited.find(ltempString);
				if(iter != imVisited.end() && iter->second == false)
				{
					iter->second = true;
					irvResult[level + 1] = ltempString;
					hfindLadders(ltempString, end, imVisited, irvResult, level + 1, iorvvFinalResult);
					iter->second = false;
				}
			}
		}
	}

	vector<vector<string>> findLadders(string start, string end, set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		dict.insert(end);
		map<string, bool> lmVisited;
		set<string>::iterator iter = dict.begin();
		for(; iter != dict.end(); iter ++)
		{
			lmVisited[*iter] = false;
		}

		vector<string> lvResult(dict.size() + 2);
		vector<vector<string> > lvvFinalResult;
		
		lvResult[0] = start;
		hfindLadders(start, end, lmVisited, lvResult, 0, lvvFinalResult);

		vector<vector<string>>::iterator lvviter = lvvFinalResult.begin();
		int minlen = 1000000;
		for(; lvviter != lvvFinalResult.end(); lvviter ++)
			if(minlen > lvviter->size())
				minlen = lvviter->size();

		vector<vector<string> > lvvFinalResult2;
		for(lvviter = lvvFinalResult.begin(); lvviter != lvvFinalResult.end(); lvviter ++)
		{
			if(lvviter->size() == minlen)
			{
				lvvFinalResult2.push_back(*lvviter);
			}
		}

		return lvvFinalResult2;
    }
	
};



int main()
{
	Solution mySolution;

	string start("hit");
	string end("cog");
	set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	int ladder = mySolution.ladderLength(start, end, dict);

	mySolution.findLadders(start, end, dict);

	return 0;
}
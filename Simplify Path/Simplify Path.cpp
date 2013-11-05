#include <iostream>
#include <string>
#include <stack>
using namespace std;


string pattern1 = "./";
string pattern2 = "../";
string pattern3 = "/";
string pattern4 = ".";
string pattern5 = "..";

class Solution {
public:
	int nextPattern(string& path, int start)
	{
		int count = 1;
		int pathlen = path.length();
		while(path[start++]!= '/' && start < pathlen)
		{
			count ++;
		}
		return count;
	}
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(path.empty()) return path;

		stack<string> pathStack;
		int pathlen = path.length();
		int start = 0;
		int count = 0;
		while(start < pathlen)
		{
		     count = nextPattern(path, start);
			 string curPattern = path.substr(start, count);
			 if(curPattern == pattern1 || curPattern == pattern4)
			 {
				//nothing
			 }
			 else if(curPattern == pattern2 || curPattern == pattern5)
			 {
				 if(!pathStack.empty() && pathStack.top() != pattern3)
				 {
					 pathStack.pop();
				 }
			 }
			 else if(curPattern == pattern3)
			 {
				 if(pathStack.empty())
					 pathStack.push(curPattern);
			 }
			 else
			 {
				 pathStack.push(curPattern);
			 }

			 start += count;
		}
		if(!pathStack.empty())
		{
			string topPattern = pathStack.top();
			if(topPattern.length() > 1 && topPattern[topPattern.length() - 1] == '/')
			{
				string tmpPattern = topPattern.substr(0, topPattern.length() - 1);
				pathStack.pop();
				pathStack.push(tmpPattern);
			}
		}

		string result;
		while(!pathStack.empty())
		{
			result = pathStack.top() + result;
			pathStack.pop();
		}
		return result;
    }
};

int main()
{
	Solution mS;
	string path;
	while(cin >> path)
	{
		cout << mS.simplifyPath(path) << endl;;
	}
	return 0;
}
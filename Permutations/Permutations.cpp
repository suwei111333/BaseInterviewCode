#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> used(num.size(), false);
        vector<int> path;
        vector<vector<int> > ret;

        sort(num.begin(), num.end());
        sub(num, used, path, ret);
        return ret;
    }

    void sub(vector<int> &num, vector<bool> &used, vector<int> &path, vector<vector<int> > &ret) {
        if (num.size() == path.size()) {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < num.size(); ++i) {
            if (used[i] || (i != 0 && num[i] == num[i - 1] && used[i - 1])) continue;
            used[i] = true;
            path.push_back(num[i]);
            sub(num, used, path, ret);
            used[i] = false;
            path.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > lvFinalResult;
		if(num.empty()) return lvFinalResult;

		hPermute(0, num, lvFinalResult);

		return lvFinalResult;
    }

	void hPermute(int index, vector<int>& num, vector<vector<int> >& orvFinalResult)
	{
		if(index >= num.size())
		{
			orvFinalResult.push_back(num);
			return;
		}

		for(int i = index; i< num.size(); i++ )
		{
			swap(num[index], num[i]);
			hPermute(index + 1, num, orvFinalResult);
			swap(num[index], num[i]);
		}
	}
};


int main()
{
	Solution mS;

	int a[] = {1,2,3};
	vector<int>  lvNum(a, a + sizeof(a)/sizeof(int));

	vector<vector<int> > lvvResult = mS.permute(lvNum);

	Solution1 mSS;
	int b[]= {1,1,1,2,2};
	vector<int> lvNum1(b, b + sizeof(b)/sizeof(int));
	vector<vector<int> > lvvResult1 = mSS.permuteUnique(lvNum1);

	next_permutation();
	return 0;
}
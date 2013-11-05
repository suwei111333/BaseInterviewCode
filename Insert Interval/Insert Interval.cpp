#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(intervals.empty() 
			|| newInterval.start > intervals[intervals.size() - 1].end)
		{	
			intervals.push_back(newInterval);
			return intervals;
		}
		if(newInterval.end < intervals[0].start)
		{
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}
		
		bool lbFlag = true;
		vector<Interval> lvResult;
		for(int i = 0; i< intervals.size(); i++)
		{
			if(newInterval.start > intervals[i].end)
			{
				lvResult.push_back(intervals[i]);
				continue;
			}

			if(newInterval.end < intervals[i].start)
			{
				if(lbFlag)
				{
					lvResult.push_back(newInterval);
					lbFlag = false;
				}

				lvResult.push_back(intervals[i]);
				continue;
			}
			newInterval.start = min(newInterval.start, intervals[i].start);
			newInterval.end = max(newInterval.end, intervals[i].end);
		}
		
		if(lbFlag)
			lvResult.push_back(newInterval);

		return lvResult;
		
    }
};

int main()
{
	Solution mS;
	vector<Interval> lvInterval;
	lvInterval.push_back(Interval(1,2));
	lvInterval.push_back(Interval(3,5));
	lvInterval.push_back(Interval(6,7));
	lvInterval.push_back(Interval(8,10));
	lvInterval.push_back(Interval(12,19));

	lvInterval = mS.insert(lvInterval, Interval(3, 9));
	return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	class cmp
	{
	public:
		bool operator()(const Interval& a, const Interval& b)
		{
			 if(a.start != b.start)
				 return a.start < b.start;
			 else
				 return a.end < b.end;
		}
	};
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(intervals.empty() || intervals.size() == 1) return intervals;

		sort(intervals.begin(), intervals.end(), Solution::cmp());

		vector<Interval> lvResult;
		Interval newInterval = intervals[0];
		for(int i = 1; i< intervals.size(); i++)
		{
			if(intervals[i].start > newInterval.end)
			{
				lvResult.push_back(newInterval);
				newInterval = intervals[i];
			}
			else
			{
				newInterval.end = max(intervals[i].end, newInterval.end);
			}
		}
		
		lvResult.push_back(newInterval);

		return lvResult;
    }
};


int main()
{
	vector<Interval> lvIntervals;
	lvIntervals.push_back(Interval(2, 6));
	lvIntervals.push_back(Interval(1, 3));
	lvIntervals.push_back(Interval(15, 18));
	lvIntervals.push_back(Interval(8, 10));

	Solution mS;
	lvIntervals = mS.merge(lvIntervals);


	return 0;
}
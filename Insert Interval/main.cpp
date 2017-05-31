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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      int start=-1;
      int end=-1;
        for(int i=0;i<intervals.size();i++){
          if(start==-1&&intervals[i].end>=newInterval.start&&intervals[i].start<=newInterval.start){
            newInterval.start=intervals[i].start;
            start=i;
          }
          else if(start==-1&&intervals[i].end>=newInterval.start&&intervals[i].start>=newInterval.start){
            start=i;
          }
          if(end==-1&&intervals[i].end>=newInterval.end&&intervals[i].start<=newInterval.end){
              end=i+1;
            newInterval.end=intervals[i].end;
            break;
          }
          else if(end==-1&&intervals[i].end>=newInterval.end&&intervals[i].start>=newInterval.end){
            end=i;
            break;
          }
        }
        if(end==-1)
          end=intervals.size();
        if(start==-1)
          start=intervals.size();
        intervals.erase(intervals.begin()+start,intervals.begin()+end);
        intervals.insert(intervals.begin()+start,newInterval);
        return intervals;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

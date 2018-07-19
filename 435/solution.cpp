/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval a,Interval b){
        return a.start < b.start;
    }
    
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int ans = 0;
        if(intervals.empty()){
            return ans;
        }
        
        sort(intervals.begin(),intervals.end(),cmp);
        Interval cur = intervals[0];
        for(int i = 1;i < intervals.size(); ++i){
            if(cur.end > intervals[i].start){
                ans++;
                if(cur.end > intervals[i].end){
                    cur = intervals[i];
                }
            }else{
                cur = intervals[i];
            }
        }
        
        return ans;
    }
};
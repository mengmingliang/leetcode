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
    static bool cmp(Interval & a, Interval & b){
        return a.start < b.start;
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int i = 0;
        int n = intervals.size();
        
        while(i < n &&  intervals[i].start <= newInterval.start){
            ans.push_back(intervals[i]);
            ++i;
        }
        
        if(ans.empty()){
            ans.push_back(newInterval);
        }else{
            int start = ans[ans.size()-1].start;
            int end = ans[ans.size()-1].end;
            
            if(newInterval.end > end){
                if(newInterval.start <= end){
                    ans.pop_back();
                    ans.push_back(Interval(start,newInterval.end));
                }else{
                    ans.push_back(newInterval);
                }
                
            }
        }
        
        
        while(i < n){
            int start = ans[ans.size()-1].start;
            int end = ans[ans.size()-1].end;
            if(intervals[i].end <= end){
                ++i;
                continue;
            }else{
                if(intervals[i].start <= end){
                    ans.pop_back();
                    ans.push_back(Interval(start,intervals[i].end));
                }else{
                    ans.push_back(intervals[i]);
                }
                ++i;
            }
        }
        
        return ans;
    }
};

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
    static bool cmp(Interval & a, Interval & b){
        return a.start < b.start;
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        for(auto e: intervals){
            if(ans.empty()){
                ans.push_back(e);
            }else{
                int start = ans[ans.size()-1].start;
                int end = ans[ans.size()-1].end;
                if(e.end <= end){
                    continue;
                }else{
                    if(e.start <= end){
                        ans.pop_back();
                        ans.push_back(Interval(start,e.end));
                    }else{
                        ans.push_back(e);
                    }
                }
            }
            
        }
        
        return ans;
    }
};
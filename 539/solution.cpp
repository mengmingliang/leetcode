class Solution {
public:
   void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2){
            v.push_back(s.substr(pos1, pos2-pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }
    
    int minDifference(pair<int,int> time1,pair<int,int> & time2){
        int ans = INT_MAX;
        int val = 0;
        
        if(time1.first < time2.first){
            val = (time2.first - time1.first- 1)*60 + time2.second + 60 -  time1.second;
            ans = min(val,24*60 - val);
        }else if(time1.first > time2.first){
            val = (time1.first - time2.first- 1)*60 + time1.second + 60 -  time2.second;
            ans = min(val,24*60 - val);
        }else{
            ans = abs(time1.second-time2.second);
        }
        
        return ans;
    }
    
    static bool compare(pair<int,int> & a,pair<int,int> &b){
        if(a.first < b.first){
            return true;
        }else if(a.first == b.first){
            return a.second < b.second;
        }else{
            return false;
        }
    }
    
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int,int>> mytime;
        vector<string> res;
        int ans = 0;
       
        for(int i = 0;i < timePoints.size(); ++i){
            SplitString(timePoints[i],res,":");
            mytime.push_back(make_pair(stoi(res[0]),stoi(res[1])));
            res.clear();
        }
        
        sort(mytime.begin(),mytime.end(),compare); 
        ans = minDifference(mytime[0],mytime[mytime.size()-1]);
        for(int i = 1;i < mytime.size(); ++i){
            ans = min(ans,minDifference(mytime[i-1],mytime[i]));
        }
               
        return ans;
    }
};
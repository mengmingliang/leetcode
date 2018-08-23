class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<vector<int>> idx(26,vector<int>());
        bool isNeed = true;
        int ans = 0;
        int key = 0;
        
        if(s.size() <= 0){
            return 0;
        }
        
        //cout<<s<<endl;
        
        for(int i = 0;i < s.size(); ++i){
            idx[s[i]-'a'].push_back(i);
        }
        
        for(int i = 0;i < 26; ++i){
            if(idx[i].size() > 0 && idx[i].size() < k){
                isNeed = false;
                key = i;
                break;
            }
        }
        
        if(isNeed){
            return s.size();
        }
        
        int pre = 0;
        for(int i = 0;i < idx[key].size(); ++i){
            ans = max(ans,longestSubstring(s.substr(pre,idx[key][i]-pre),k));
            pre = idx[key][i]+1;
        }
        ans = max(ans,longestSubstring(s.substr(pre,s.size()-pre),k));
        
        return ans;
    }
};
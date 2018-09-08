class Solution {
public:
    string reorganizeString(string S) {
        vector<int> counter(26,0);
        string ans;
        int n = S.size();
        int idx = 0;
        int pre = -1;
        int cur = 0;
        int maxCur = 0;
        
        for(auto c: S){
            counter[c-'a']++;
        }
        
        while(idx < n){
            maxCur = 0;
            cur = -1;
            
            for(int i = 0;i < 26; ++i){
                if(pre != i && counter[i] > maxCur){
                    maxCur = counter[i];
                    cur = i;
                }
            }
            
            if(cur < 0){
                return "";
            }else{
                counter[cur]--;
                pre = cur;
                ans.push_back('a'+cur);
            }
            
            idx++;
        }
        
        return ans;
        
    }
};
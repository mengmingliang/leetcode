class Solution {
public:
    bool isChild(string & src,string & des){
        int l1 = 0;
        int l2 = 0;
        
        if(src.size() > des.size()){
            return false;
        }
        
        while(l1 < src.size() && l2 < des.size()){
            if(src[l1] == des[l2]){
                l1++;
                l2++;
            }else{
                l2++;
            }
        }
        
        if(l1 < src.size()){
            return false;
        }else{
            return true;
        }
    }
    
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        int n = strs.size();
        vector<bool> flag(n,false);
        
        if(n == 1){
            return (int)strs[0].size();
        }
        
        sort(strs.begin(),strs.end());
        
        for(int i = 0;i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j){
                    continue;
                }
                if(isChild(strs[i],strs[j])){
                    flag[i] = true;
                    break;
                }
            }
        }
        
        for(int i = n-1; i >= 0; --i){
            if(!flag[i]){
                ans = max(ans,(int)strs[i].size());
            }
        }
        
        return ans;
    }
};
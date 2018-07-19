class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int ans = 0;
        
        if(citations.size() <= 0){
            return ans;
        }
        
        for(int i = citations.size()-1; i >= 0; --i){
            ans++;
            if(citations[i] >= ans){
                continue;
            }else{
                ans--;
                break;
            }
        }
        
        return ans;
    }
};
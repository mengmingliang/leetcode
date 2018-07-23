class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n,0);
        set<int> number;
        int inc = 1;
        int dec = k+1;
        
        for(int i = 0;i < n; ++i){
            number.insert(i+1);
        }
        
        for(int i = 0;i < k; ++i){
            if(i%2 == 0){
                ans[i] = inc++;
                number.erase(ans[i]);
            }else{
                ans[i] = dec--;
                number.erase(ans[i]);
            }
        }
        
        int idx = k;
        for(auto e: number){
            ans[idx++] = e;
        }
        sort(ans.begin()+k,ans.end());
        
        return ans;
    }
};
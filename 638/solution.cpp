class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans = 0;
        int n = needs.size();
        bool canNeed = false;
        vector<int> next(n,0);
            
        for(int i = 0; i < n; ++i){
            ans += needs[i]*price[i];
        }
        
        cout<<special.size()<<endl;
        for(int i = 0;i < special.size(); ++i){
            canNeed = true;
            for(int j = 0;j < n; ++j){
                next[j] = needs[j] - special[i][j];
                if(next[j] < 0){
                    canNeed = false;
                    break;
                }
            }
            if(canNeed){
                ans = min(ans,shoppingOffers(price,special,next)+special[i][n]);
            }
        }
                
        return ans;
    }
};
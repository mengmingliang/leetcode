class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int ans = 0;
        int n = tree.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>());
        vector<int> same(n,0);
        
        if(n <= 0){
            return 0;
        }
        
        same[n-1] = 1;
        for(int i = n-2;i >= 0; --i){
            if(tree[i] == tree[i+1]){
                same[i] = same[i+1] + 1;
            }else{
                same[i] = 1;
            }
        }
        
        dp[n-1].push_back(make_pair(tree[n-1],1));
        for(int i = n-2; i >= 0; --i){
            int l = dp[i+1].size();
            if(l == 1){
                if(dp[i+1][0].first == tree[i]){
                    dp[i].push_back(make_pair(dp[i+1][0].first,dp[i+1][0].second+1));
                }else{
                    dp[i].push_back(make_pair(dp[i+1][0].first,dp[i+1][0].second));
                    dp[i].push_back(make_pair(tree[i],1));
                }
                continue;
            }
            
            bool  isHave = false;
            for(int j = 0;j < l; ++j){
                if(dp[i+1][j].first == tree[i]){
                    isHave = true;
                    break;
                }
            }
            
            if(isHave){
                for(int j = 0;j < l; ++j){
                    if(dp[i+1][j].first == tree[i]){
                        dp[i].push_back(make_pair(dp[i+1][j].first,dp[i+1][j].second+1));
                    }else{
                        dp[i].push_back(make_pair(dp[i+1][j].first,dp[i+1][j].second));
                    }
                }
                
            }else{
                dp[i].push_back(make_pair(tree[i],1));
                dp[i].push_back(make_pair(tree[i+1],same[i+1]));
            }
        }
        
        
        for(int i = 0;i < n; ++i){
            int sum = 0;
            for(int j = 0;j < dp[i].size(); ++j){
                sum += dp[i][j].second;
            }            
            ans = max(ans,sum);
        }
        
        return ans;
    }
};
class Solution {
public:
    int dfs(int amount,vector<int>& coins,int end){
        int ans = 0;
        
        for(int i = 0;i <= end; ++i){
            if(coins[i] < amount){
                ans += dfs(amount-coins[i],coins,i);
            }else if(coins[i] == amount){
                ans += 1;
            }else{
                break;
            }
        }
        
        return ans;
    }
    
    int change(int amount, vector<int>& coins) {
        int ans = 0;
        
        if(coins.size() < 0){
            return 0;
        }
        
        if(amount == 0){
            return 1;
        }
        
        sort(coins.begin(),coins.end());
        ans = dfs(amount,coins,coins.size()-1);
        return ans;
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans = 0;
        vector<int> dp(amount+1,0);
        
        if(coins.size() < 0){
            return 0;
        }
        
        if(amount == 0){
            return 1;
        }
        
        sort(coins.begin(),coins.end());
        for(int j = 0;j < coins.size(); ++j){
            for(int i = 1;i <= amount; ++i){
                    if(i == coins[j]){
                        dp[i] = dp[i] + 1;
                    }
                    if(i > coins[j]){
                        dp[i] = dp[i] + dp[i-coins[j]];
                    }
            }
        }
        
        return dp[amount];
    }
};
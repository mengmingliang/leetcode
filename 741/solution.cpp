class Solution {
public:    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        if(r == 0){
            return 0;
        }
        int c = grid[0].size();
        if(c == 0){
            return 0;
        }
        int t = r + c-1;
        int ans = 0;
        
        
        vector<vector<vector<int>>> dp(t,vector<vector<int>>(r,vector<int>(r,-1)));
        if(grid[0][0] == -1 || grid[r-1][c-1] == -1){
            return 0;
        }
        
        dp[0][0][0] = grid[0][0];
        
        for(int i = 1;i < t; ++i){
            for(int j = 0;j <= i && j < r; ++j){
                for(int k = 0;k <= i && k < r; ++k){
                    if(grid[j][i-j] == -1 || grid[k][i-k] == -1){
                        continue;
                    }
                    
                    int step = -1;
                    step = max(step,dp[i-1][j][k]);
                    step = max(step,j == 0?-1:dp[i-1][j-1][k]);
                    step = max(step,k == 0?-1:dp[i-1][j][k-1]);
                    step = max(step,(j == 0||k == 0)?-1:dp[i-1][j-1][k-1]);
                    if(step == -1){
                        continue;
                    }
                    dp[i][j][k] = grid[j][i-j] + (j == k ?0:grid[k][i-k]) + step;
                }
            }
        }
        
        if(dp[t-1][r-1][c-1] == -1){
            return 0;
        }else{
            return dp[t-1][r-1][c-1];
        }
    }
};

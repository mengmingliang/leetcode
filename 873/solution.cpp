class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        int ans = 2;
        unordered_map<int, int> idx;
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for (int i = 0; i < n; ++i) {
            idx[A[i]] = i;
        }
        
        for (int i = n-2; i >= 0; --i){
            for(int j = i+1; j < n; ++j){
                int sum = A[i] + A[j];
                dp[i][j] = 2;
                if(idx.find(sum) == idx.end()){
                    continue;
                }
                int k = idx[sum];
                dp[i][j] = dp[j][k] + 1;
                ans = max(ans,dp[i][j]);
            }
        }
        
        if(ans == 2){
            return 0;
        }
        
        return ans;
    }
};
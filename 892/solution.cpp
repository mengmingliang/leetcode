class Solution {
public:
    int sumSubseqWidths(vector<int>& A){
        int mod = 1000000007;
        int n = A.size();
        vector<long> pow2(n,1);
        long long ans = 0;
        
        sort(A.begin(),A.end());
        for(int i = 1;i < n; ++i){
            pow2[i] = (pow2[i-1]*2)%mod;
        }
        
        for(int i = 0;i < n; ++i){
            ans += (pow2[i]-1)*A[i]%mod;
            ans -= (pow2[n-i-1]-1)*A[i]%mod;
            ans = (ans + mod)%mod;
        }
        
        return (int)ans;
    }
};
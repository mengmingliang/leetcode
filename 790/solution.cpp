class Solution {
public:
    int numTilings(int N) {
        int mod = 1000000007;
        long  sum = 0;
        long  first = 0;
        long  second = 0;
        long  ans = 0;
        
        if(N < 1){
            return 1;
        }
        
        if(N == 1){
            return 1;
        }
        
        if(N == 2){
            return 2;
        }
        
        sum = 0;
        first = 1;
        second = 1;
        ans = 2;
        for(int i = 3;i <= N; ++i){
            sum = (sum + second)%mod;
            second = first;
            first = ans;
            ans = (second + first + 2*sum)%mod;
        }
        
        
        return (int)(ans);
    }
};

class Solution {
public:
    int numTilings(int N) {
        vector<long> dp(N+1,0);
        int mod = 1000000007;
        
        /*initial*/
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3;i <= N; ++i){
            dp[i] = (2*dp[i-1] + dp[i-3])%mod;
        }
        
        return dp[N];
    }
};


class Solution(object):
    def numTilings(self, N):
        """
        :type N: int
        :rtype: int
        95MS
        """
        import numpy as np
        if N == 1:
            return 1
        if N == 2:
            return 2
        if N % 2 == 1:
            k = (N - 2) // 2
            # a1,b1,c1
            start = np.array([1, 1, 2], dtype=np.int64)
        else:
            k = (N - 4) // 2
            # a2,b2,c2
            start = np.array([2, 3, 4], dtype=np.int64)
        A = np.array([[2, 3, 4], [1, 1, 2], [1, 1, 1]], dtype=np.int64)
        while k > 0:
            # 相当于转化为2进制
            if k % 2 == 1:
                start = np.dot(start, A) % 1000000007
            k //= 2
            A = A.dot(A) % 1000000007

        return int(np.dot(start, np.array([[2],[1],[1]], dtype=np.int64)) % 1000000007)




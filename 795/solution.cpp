class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int len = A.size();
        int ans = 0;
        int left = -1;//左界
        int right = -1;//最近合法位置
        
        for(int i=0; i<len; i++) {
            if(A[i] > R) {
                left = i;
                right = i;
            }
            else if(A[i]<L) {
                ans += (i-left)-(i-right);
            }
            else {
                ans += (i-left);
                right = i;
            }
        }
        return ans;
        
    }
};
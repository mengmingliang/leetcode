class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> keep(n,n);
        vector<int> swap(n,n);
        
        swap[0] = 1;
        keep[0] = 0;
        for(int i = 1;i < n; ++i){
            if(A[i] > A[i-1] && B[i] > B[i-1]){
                swap[i] = swap[i-1] +1;
                keep[i] = keep[i-1];
            }
            if(A[i] > B[i-1] && B[i] > A[i-1]){
                keep[i] = min(keep[i],swap[i-1]);
                swap[i] = min(swap[i],keep[i-1]+1);
            }
        }
        
        return min(swap[n-1],keep[n-1]);
    }
};
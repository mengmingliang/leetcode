class Solution {
public:
    
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int r = A.size();
        int c = A[0].size();
        int ans = 0;
        int one = 0;
        
        /*down & right*/
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                one = 0;
                for(int m = i; m < r; ++m){
                    for(int n = j; n < c; ++n){
                        if(A[m][n] == 1 && B[m-i][n-j] == 1){
                            one++;
                        }
                    }
                }
                ans = max(one,ans);
            }
        }
        
        /*up & left*/
        for(int i = r - 1;i >= 0; --i){
            for(int j = c-1 ;j >= 0; --j){
                one = 0;
                for(int m = i; m >= 0; --m){
                    for(int n = j; n >= 0; --n){
                        if(A[m][n] == 1 && B[r-1+m-i][c-1+n-j] == 1){
                            one++;
                        }
                    }
                }
                ans = max(one,ans);
            }
        }
        
        /*down & left*/
        for(int i = 0;i < r; ++i){
            for(int j = c-1 ; j >= 0; --j){
                one = 0;
                for(int m = i;m < r; ++m){
                    for(int n = j; n >= 0; --n){
                        if(A[m][n] == 1 && B[m-i][c-1+n-j] == 1){
                            one++;
                        }
                    }
                }
                ans = max(one,ans);
            }
        }
        
        /*up & right*/
        for(int i = r-1; i >= 0; --i){
            for(int j = 0;j < c; ++j){
                one = 0;
                for(int m = i; m >= 0; --m){
                    for(int n = j; n < c; ++n){
                        if(A[m][n] == 1 && B[r-1+m-i][n-j] == 1){
                            one++;
                        }
                    }
                }
                ans = max(one,ans);
            }
        }
        
        return ans;
    }
};
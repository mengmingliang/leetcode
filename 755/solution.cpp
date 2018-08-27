class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for(int i = 0;i < A.size()-1;){
            if(A[i] == i){
                i++;
                continue;
            }
            if(A[i] == i+1 && A[i+1] == i){
                i = i+2;
                continue;
            }else{
                return false;
            }
        }
        
        return true;
    }
};
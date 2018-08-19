class Solution {
public:
  
    
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0;
        int sumB = 0;
        map<int,int> mapA;
        map<int,int> mapB;
        vector<int> ans;
        
        for(int i = 0;i < A.size(); ++i){
            sumA += A[i];
            mapA[A[i]] = i;
        }
        for(int i = 0;i < B.size(); ++i){
            sumB += B[i];
            mapB[B[i]] = i;
        }
        
        int distance = (sumB - sumA)/2;
        
        for(int i = 0; i < A.size(); ++i){
            if(mapB.find(A[i]+distance)!=mapB.end()){
                ans.push_back(A[i]);
                ans.push_back(A[i]+distance);
                break;
            }
        }
        
        return ans;
    }
};
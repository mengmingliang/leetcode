class Solution {
public:
    bool dfs(vector<int> & res,int target,int next){
        for(int i = 0; i <= 9; ++i){
            if(next +i <= target){
                res.push_back(next+i);
                dfs(res,target,(next+i)*10);
            }else{
                break;
            }
        }
        
        return true;
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int length = 0;
        int next = 0;
        
        for(int i = 1;i <= 9; ++i){
            if(i<= n){
                ans.push_back(i);
                dfs(ans,n,i*10);
            }else{
                break;
            }
        }
        
        return ans;
    }        
       
};
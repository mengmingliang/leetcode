class Solution {
public:
    bool dfs(int start,int end,int k,vector<int> & path,vector<vector<int>> & res){
        if(k == 0){
            res.push_back(path);
            return true;
        }
        
        if(end - start + 1 < k || start > end){
            return false;
        }
        
        for(int i = start;i <= end; ++i){
            path.push_back(i);
            dfs(i+1,end,k-1,path,res);
            path.pop_back();
        }
        
        return true;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(1,n,k,path,ans);
        
        return ans;
    }
};
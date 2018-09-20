class Solution {
public:
    void dfs(vector<bool>& visited,vector<int> & path,set<vector<int>> &mySet,vector<int>& nums , int n){
        if(n == nums.size()){
            mySet.insert(path);
            return;
        }
        
        for(int i = 0 ; i < nums.size(); ++i){
            if(!visited[i]){
                visited[i] = true;
                path.push_back(nums[i]);
                dfs(visited,path,mySet,nums,n+1);
                visited[i] = false;
                path.pop_back();
            }
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);
        vector<int> path;
        vector<vector<int>> ans;
        set<vector<int>> mySet;
        
        dfs(visited,path,mySet,nums,0);
        for(auto e:mySet){
            ans.push_back(e);
        }
        
        return ans;
    }
};

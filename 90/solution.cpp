class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> &path, vector<int> &nums, int start){
        res.push_back(path);
        
        if(start >= nums.size()){
            return;
        }
        
        for(int i = start; i < nums.size(); ++i){
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            dfs(res,path,nums,i+1);
            path.pop_back();
        }
    }                                                                        
 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> path;
        vector<vector<int>> res;
        
        dfs(res,path,nums,0);
        
        return res;
    }
};

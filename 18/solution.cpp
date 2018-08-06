class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        int l = 0;
        int r = 0;
        
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n-3; ++i){
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            for(int j = i + 1; j < n-2; ++j){
                if(j > i + 1 && nums[j-1] == nums[j]){
                    continue;
                }
                l = j + 1;
                r = n - 1;
                
                int sum = target - nums[i] - nums[j];
                while(l < r){
                    if(l > j + 1 && nums[l-1] == nums[l]){
                        l++;
                        continue;
                    }
                    if(r < n - 1 && nums[r] == nums[r+1]){
                        r--;
                        continue;
                    }
                    
                    if(nums[l] + nums[r] == sum){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[l]);
                        tmp.push_back(nums[r]);
                        ans.push_back(tmp);
                        l++;
                        r--;
                    }else if(nums[l] + nums[r] < sum){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        
        return ans;
    }
};
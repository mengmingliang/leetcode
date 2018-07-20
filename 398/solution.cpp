class Solution {
public:
    Solution(vector<int> nums) {
        for(int i = 0;i < nums.size(); ++i){
            if(key.find(nums[i]) != key.end()){
                key[nums[i]].push_back(i);
            }else{
                vector<int> tmp;
                tmp.push_back(i);
                key[nums[i]] = tmp;
            }
        }
    }
    
    int pick(int target) {
       int n = key[target].size();
       return key[target][random()%n];
    }
private:
    map<int,vector<int>> key;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
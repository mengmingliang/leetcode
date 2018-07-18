class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans;
        int n = nums.size();
        
        if( n <= 0){
            return  ans;
        }
        if(n == 1){
            return to_string(nums[0]);
        }
        if(n == 2){
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        
        ans = to_string(nums[0]) + "/";
        string tmp = to_string(nums[1]);
        for(int i = 2;i < nums.size(); ++i){
            tmp += "/" + to_string(nums[i]);
        }
        ans = ans + "(" + tmp + ")";
        
        return ans;
    }
};
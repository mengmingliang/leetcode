class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> result;
        result[0] = 1;
        int sum = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (result.find(sum - k) != result.end()) {
                count += result[sum - k];
            }
            ++result[sum];
        }
        
        return count;
    }
};
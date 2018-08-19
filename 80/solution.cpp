class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int cnt = 0;
        
        for(int i = 0;i < nums.size(); ++i){
            if(nums[i] == nums[start]){
                cnt++;
                if(cnt <= 2){
                    nums[end++] = nums[i];
                }
            }else{
                cnt = 1;
                nums[end++] = nums[i];
                start = i;
            }
        }
        
        return end;
    }
};
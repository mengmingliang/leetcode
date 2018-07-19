class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        int result = 0;
        
        for(int i=0;i<32;i++)
        {
            int mask = 1<<i;
            int cnt = 0;
            for(int j=0;j<length;j++)
            {
                if(mask & nums[j])
                    cnt++;
            }
            if(cnt%3)
                result |= mask;
        }
        return result;
    }
};
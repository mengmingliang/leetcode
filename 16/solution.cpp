typedef vector<int>::iterator it;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int distance = INT_MAX;
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        if(n <= 2){
            return -1;
        }
     
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i < n - 2; ++i){
            for(l = i+1,r = n-1;l < r;){
                int sum = nums[i] + nums[l] + nums[r];
                //cout<<sum<<endl;
                if(sum > target){
                    if(sum - target < distance){
                        distance = sum - target;
                        ans = sum;
                    }
                    r--;
                }else if(sum < target){
                    if(target - sum < distance){
                        distance = target - sum;
                        ans = sum;
                    }
                    l++;
                }else{
                    return target;
                }
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    bool binarySearch(vector<int> & nums,int l,int r,int target){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return true;
            }else if(nums[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        for(int i = 0;i < nums.size(); ++i){
            if(nums[i] > nums[i+1]){
                return binarySearch(nums,0,i,target)||binarySearch(nums,i+1,n-1,target);
            }
        }
        
        return binarySearch(nums,0,n-1,target);
    }
};
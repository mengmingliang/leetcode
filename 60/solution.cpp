class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> f(n+1,1);
        int sum = 1;
        string ans;
        string nums = "123456789";
        
        for(int i = 1;i <= n; ++i){
            sum = sum*i;
            f[i] = sum;
        }
        
        if(n <= 0){
            return ans;
        }
        
        if(k <= 0 || k > sum){
            return ans;
        }
        
        k--;
        for(int i = n-1;i >= 0; --i){
           int next = k/f[i];
            k = k%f[i];
           ans.push_back(nums[next]);
           nums.erase(next,1);
        }
                
        return ans;
    }
};
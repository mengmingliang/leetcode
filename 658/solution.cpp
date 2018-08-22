class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> ans;
        
        vector<int>::iterator it = lower_bound(arr.begin(),arr.end(),x);
        if(it == arr.end()){
            for(int i = n-x; i < n; ++i){
                ans.push_back(arr[i]);
                return ans;
            }
        }
        
        int val = it - arr.begin();
        int r = 0;
        int l = -1;
        
        while(k > 0){
            if(val + r == n){
                ans.push_back(arr[val+l]);
                l--;
                k--;
                continue;
            }
            if(val + l < 0){
                ans.push_back(arr[val+r]);
                r++;
                k--;
                continue;
            }
            if(abs(arr[val+l]-x) > abs(arr[val+r]-x)){
                ans.push_back(arr[val+r]);
                r++;
                k--;
            }else{
                ans.push_back(arr[val+l]);
                l--;
                k--;
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
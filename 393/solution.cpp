class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        
        if(citations.size() <= 0){
            return ans;
        }
        
        for(int i = citations.size()-1; i >= 0; --i){
            ans++;
            if(citations[i] >= ans){
                continue;
            }else{
                ans--;
                break;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        int n = citations.size();
        int l = 0;
        int r = citations.size()-1;
        
        if(citations.size() <= 0){
            return ans;
        }
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if(citations[mid] == n - mid){
                return n - mid;
            }else if(citations[mid] > n - mid){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return n - l;
    }
};

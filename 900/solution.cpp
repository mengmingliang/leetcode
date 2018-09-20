class RLEIterator {
public:
    RLEIterator(vector<int> A) {
        length = 0;
        for(int i = 0;i < A.size(); i += 2){
            nums.push_back(make_pair(A[i],A[i+1]));
            length += A[i];
        }
        reverse(nums.begin(),nums.end());
    }
    
    int next(int n) {
        int ans = 0;
        
        if(n > length){
            length = 0;
            nums.clear();
            return -1;
        }
        
        length -= n;
        while(n > 0){
            int last = nums.size()-1;
            if(nums[last].first >= n){
               nums[last].first -= n;
               ans = nums[last].second;
               if(nums[last].first == 0){
                   nums.pop_back();
               }
               return ans;
            }else{
               n -= nums[last].first;
               nums.pop_back(); 
            }
        }
        
        return ans;
    }
private:
    vector<pair<int,int>> nums;
    long long length;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
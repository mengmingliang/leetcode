class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        int n = num.size();
        int idx = n-1;
        
        if(num.size() <= 0){
            num.push_back(price);
            dp.push_back(ans);
            return 1;
        }
        
        num.push_back(price);
        while(idx >= 0){
            if(price >= num[idx]){
                ans += dp[idx];
                idx -= dp[idx];
            }else{
                break;
            }
        }
        
        dp.push_back(ans);
        return ans;
    }
private:
    vector<int> dp;
    vector<int> num;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size();
        int sum = 0;
        for(auto e: piles){
            sum += e;
        }
        
        int low = max(1,sum/H);
        int high = *max_element(piles.begin(), piles.end());
        
        while (low != high) {
            int mid = (low + high) / 2;
            long  speed = 0;
            for (int i = 0; i < n; ++i) {
                speed += (piles[i] + mid - 1) / mid;
            }
            if (speed > H) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high;
    }
};
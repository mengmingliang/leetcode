class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(),ages.end());
        
        for(int i = ages.size()-1; i >= 1; --i){
            for(int j = i-1; j >= 0; --j){
                if(ages[j] > ages[i]*0.5 + 7){
                    if(ages[i] == ages[j]){
                        ans += 2;
                    }else{
                        ans += 1;
                    }
                }
            }
        }
        
        return ans;
    }
};


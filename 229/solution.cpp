class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int num1 = 0;
        int num2 = 0;
        int length = nums.size();
        vector<int> ans;
        
        for(auto e: nums){
            if(count1 == 0){
                count1++;
                num1 = e;
            }else if(num1 == e){
                count1++;
            }else if(count2 == 0){
                count2++;
                num2 = e;
            }else if(num2 == e){
                count2++;
            }else{
                count1--;
                count2--;
                if(count1 == 0 && count2 > 0){
                    count1 = count2;
                    num1 = num2;
                    count2 = 0;
                    num2 = 0;
                }
            }
        }
        
        if(count1 > 0){
            count1 = 0;
            for(auto e: nums){
                if(e == num1){
                    count1++;
                }
            }
        }
        
        if(count2 > 0){
            count2 = 0;
            for(auto e: nums){
                if(e == num2){
                    count2++;
                }
            }
        }
        
        if(count1*3 > length ){
            ans.push_back(num1);
        }
        if(count2*3 > length){
            ans.push_back(num2);
        }
        
        return ans;
    }
};
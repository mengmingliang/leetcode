class Solution {
public:
    static bool cmp(string a,string b){
        string c1 = a + b;
        string c2 = b + a;
        return c1 > c2;
    }
    
    string largestNumber(vector<int>& nums) {
        if(nums.size() <= 0){
            return "";
        }
        
        vector<string> num_str;
        for(int i = 0;i < nums.size(); ++i){
            num_str.push_back(to_string(nums[i]));
        }
        
        std::sort(num_str.begin(),num_str.end(),cmp);
        string ans = "";
        for(int i = 0;i < num_str.size(); ++i){
            ans += num_str[i];
        }
        
        if(ans[0] == '0'){
            return "0";
        }
        
        return ans;
    }
};


class Solution {
public:
  
    string originalDigits(string s) {
        vector<int> digit(10,0);
        vector<int> nums(26,0);
        string ans;
        
        for(int i = 0;i < s.size(); ++i){
            nums[s[i]-'a']++;
        }
        
        int target[10] = {0,2,4,6,8,5,7,1,3,9};
        string words[10] = {"zero","two","four","six","eight",\
                      "five","seven","one","three","nine"};
        char key[10] = {'z','w','u','x','g','f','s','o','t','i'};
        
        
        for(int i = 0;i < 10; ++i){
            int cnt = nums[key[i]-'a'];
            for(int j = 0;j < words[i].size(); ++j){
                nums[words[i][j]-'a'] -= cnt;
            }
            digit[target[i]] = cnt;
        }
        
        for(int i = 0;i < digit.size(); ++i){
            for(int j = 0;j < digit[i]; ++j){
                ans = ans + to_string(i);
            }
        }
        
        return ans;
    }
};
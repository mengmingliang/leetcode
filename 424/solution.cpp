class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int n = s.size();
        vector<int> counter(26,0);
        
        if(s.size() <= 0){
            return 0;
        }
        
        counter[s[start]-'A']++;
        while(end < s.size()){
            int maxCur = 0;
            for(int i = 0;i < 26; ++i){
                maxCur = max(maxCur,counter[i]);
            }
            
            if(maxCur + k > end - start){
                end++;
                if(end < s.size()){
                    counter[s[end]-'A']++;
                }
            }else{
                counter[s[start]-'A']--;
                start++;
            }
            
            ans = max(ans,min(n,maxCur+k));
        }
        
        return ans;
    }
};
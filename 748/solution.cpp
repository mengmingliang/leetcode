class Solution {
public:
    bool isValid(string & s,vector<int> & counter){
        vector<int> nmp(26,0);
        for(auto c:s){
            c = tolower(c);
            if(c >= 'a' && c <= 'z'){
                nmp[c-'a']++;
            }
        }
        
        for(int i = 0;i < 26; ++i){
            if(counter[i] != 0 && nmp[i] < counter[i]){
                return false;
            }
        }
        
        return true;
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> counter(26,0);
        string ans;
        int minLen = INT_MAX;
        
        for(auto c : licensePlate){
            c = tolower(c);
            if(c >= 'a' && c <= 'z'){
                counter[c-'a']++;
            }
        }
        
        for(auto w: words){
            if(isValid(w,counter)){
                if(w.size() < minLen){
                    minLen = w.size();
                    ans = w;
                }
            }
        }
        
        return ans;
    }
};
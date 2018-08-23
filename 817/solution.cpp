class Solution {
public:
    bool checkValid(string s){
        int n = s.size();
        
        if(n <= 0){
            return false;
        }
        
        if(n == 1){
            return true;
        }else{
            if(s[0] == '0' && s[n-1] == '0'){
                return false;
            }
        }
        
        return true;
    }
    
    bool canSplit(string S,int idx){
        int n = S.size();
        if(idx < 0 || idx >= S.size()){
            return false;
        }
        
        string s1 = S.substr(0,idx+1);
        string s2 = S.substr(idx+1,n-idx-1);
        
        if(checkValid(s1)&&checkValid(s2)){
            return true;
        }else{
            return false;
        }
    }
    
    bool isInteger(string S){
        int n = S.size();
        
        if(S[0] == '0' && n > 1){
            return false;
        }else{
            return true;
        }
    }
    
    bool isDigitNum(string S,int point){
        if(!checkValid(S)){
            return false;
        }
        
        if(point < 0 || point >= S.size() - 1){
            return false;
        }
        
        int n = S.size();
        if(n <= 1){
            return false;
        }
        
        if(S[0] == '0'&& point > 0){
            return false;
        }
        
        if(S[0] != '0' && S[n-1] == '0'){
            return false;
        }
        
        return true;
    }
    
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ans;
        vector<string> first;
        vector<string> second;
        int n = S.size();
        
        S = S.substr(1,n-2);
        if(n <= 1){
            return ans;
        }
        
        for(int i = 0;i < S.size()-1; ++i){
            first.clear();
            second.clear();
            if(canSplit(S,i)){
                string s1 = S.substr(0,i+1);
                string s2 = S.substr(i+1,n-i-1);
                
                if(isInteger(s1)){
                    first.push_back(s1);
                }
                for(int i = 0;i < s1.size()-1; ++i){
                    if(isDigitNum(s1,i)){
                        first.push_back(s1.substr(0,i+1) + "." + s1.substr(i+1,s1.size()-i-1));
                    }
                }
                
                if(isInteger(s2)){
                    second.push_back(s2);
                }
                for(int i = 0;i < s2.size()-1; ++i){
                    if(isDigitNum(s2,i)){
                        second.push_back(s2.substr(0,i+1) + "." + s2.substr(i+1,s2.size()-i-1));
                    }
                }
                
                for(int i = 0;i < first.size(); ++i){
                    for(int j = 0;j < second.size(); ++j){
                        ans.push_back("("+first[i]+", "+second[j]+")");
                    }
                }
            }
        }
        
       
        
        return ans;
    }
};
class Solution {
public:
    bool isWord(string & src,string & dst){
        int l = 0;
        int r = 0;
        while(l < src.size() && r < dst.size()){
            if(src[l] == dst[r]){
                l++;
                r++;
            }else{
                l++;
            }
        }
        
        if(r < dst.size()){
            return false;
        }else{
            return true;
        }
    }
    
    static bool compare(string & src,string & dst){
        if(src.size() > dst.size()){
            return true;
        }else if(src.size() == dst.size()){
            return src < dst ? true:false;
        }else{
            return false;
        }        
    }
    
    string findLongestWord(string s, vector<string>& d) {
        vector<int> dst(26,0);
        sort(d.begin(),d.end(),compare);
        string ans;
        
        for(int i = 0;i < s.size(); ++i){
            dst[s[i]-'a']++;
        }
        
        for(auto e: d){
            if(isWord(s,e)){
                ans = e;
                break;
            }   
        }
        
        return ans;
    }
};
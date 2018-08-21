class Solution {
public:
    
    bool isReplacePattern(string word,map<char,vector<int>> & pattern_map,int length){
        set<char> key;
        
        if(word.size() != length){
            return false;
        }
        
        for(auto e: pattern_map){
           char c;
           for(int i = 0;i < e.second.size(); ++i){
               if(i == 0){
                   c = word[e.second[i]];
                   if(key.find(c) != key.end()){
                       return false;
                   }
                   key.insert(c);
               }else{
                   if(word[e.second[i]] != c){
                       return false;
                   }
               }
               
           }
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        map<char,vector<int>> pattern_map;
        int length = pattern.size();
        vector<int> path;
        vector<string> ans;
        
        for(int i = 0;i < pattern.size(); ++i){
            if(pattern_map.find(pattern[i]) == pattern_map.end()){
                pattern_map[pattern[i]] = path;
                pattern_map[pattern[i]].push_back(i);
            }else{
                pattern_map[pattern[i]].push_back(i);
            }
        }
        
        for(auto w:words){
            if(isReplacePattern(w,pattern_map,length)){
                ans.push_back(w);
            }
        }
        
        return ans;
    }
};
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i = 0;i < dict.size(); ++i){
            lookup.insert(dict[i]);
            for(int j = 0;j < dict[i].size(); ++j){
                char c = dict[i][j];
                dict[i][j] = '*';
                lookup.insert(dict[i]);
                dict[i][j] = c;
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if(lookup.find(word) != lookup.end()){
            return false;
        }
        
        for(int i = 0;i < word.size(); ++i){
            char c = word[i];
            word[i] = '*';
            if(lookup.find(word) != lookup.end()){
                return true;
            }
            word[i] = c;
        }
        
        return false;
    }
private:
    set<string> lookup;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
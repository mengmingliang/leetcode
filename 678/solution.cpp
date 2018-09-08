class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string word : dict) s.insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); ++i) {
            char t = word[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == t) continue;
                word[i] = c;
                if (s.count(word)){
                    return true;
                }
                    
            }
            word[i] = t;
        }
        return false;
    }
    
private:
    unordered_set<string> s;
};
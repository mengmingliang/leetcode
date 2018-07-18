class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> dnaMap;
        vector<string> ans;
        
        if(s.size() < 10){
            return ans;
        }
        
        for(int i = 0;i <= s.size()-10; ++i){
            string dna = s.substr(i,10);
            if(dnaMap.find(dna)!=dnaMap.end()){
                dnaMap[dna]++;
            }else{
                dnaMap[dna] = 1;
            }
        }
        
        for(auto e:dnaMap){
            if(e.second > 1){
                ans.push_back(e.first);
            }
        }
        
        return ans;
    }
};
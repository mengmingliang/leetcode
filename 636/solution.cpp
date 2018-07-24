class Solution {
public:
    void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        vector<int> start;
        
        for(int i = 0;i < logs.size(); ++i){
            vector<string> parse;
            SplitString(logs[i],parse,":");
            int idx = atoi(parse[0].c_str());
            int t = atoi(parse[2].c_str());
            if(start.empty()){
                start.push_back(t);
            }else{
                if(parse[1] == "start"){
                    start.push_back(t);
                }else{
                    int waste = t - start[start.size()-1] + 1;
                    ans[idx] += waste;
                    start.pop_back();
                    if(!start.empty()){
                        for(int i = 0;i < start.size(); ++i){
                            start[i] += waste;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
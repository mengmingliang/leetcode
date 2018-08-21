class Solution {
public:
    bool dfsLevel(string &bottom,map<string,vector<char>> &lookup){
        vector<vector<char>> next;
        vector<string> res;
        string path;
        
        if(bottom.size() <= 1){
            return true;
        }
        
        for(int i = 0;i < bottom.size()-1; ++i){
            string key = bottom.substr(i,2);
            if(lookup.find(key) == lookup.end()){
                return false;
            }else{
                next.push_back(lookup[key]);
            }
        }
        dfsButtom(next,0,res,path);
        
        for(int i = 0;i < res.size(); ++i){
            if(dfsLevel(res[i],lookup)){
                return true;
            }
        }
        
        return false;
    }
    
    bool dfsButtom(vector<vector<char>> & p,int idx,vector<string> & res,string &path){
        if(idx >= p.size()){
            res.push_back(path);
            return true;
        }
        
        for(int i = 0;i < p[idx].size(); ++i){
            path.push_back(p[idx][i]);
            dfsButtom(p,idx+1,res,path);
            path.pop_back();
        }
        
        return true;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        map<string,vector<char>> lookup;
        
        if(n <= 0){
            return false;
        }
        
        if(n == 1){
            return true;
        }
        
        for(int i = 0;i < allowed.size(); ++i){
            string key = allowed[i].substr(0,2);
            if(lookup.find(key)!=lookup.end()){
                lookup[key].push_back(allowed[i][2]);
            }else{
                vector<char> tmp;
                tmp.push_back(allowed[i][2]);
                lookup[key] = tmp;
            }
        }
        
        return dfsLevel(bottom,lookup);
    }
};
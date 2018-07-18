class Solution {
public:
    bool dfs(string s,int n,vector<string> &path,vector<vector<string>> &res){
        if(s.size() > n*3){
            return false;
        }
        
        if(n <= 0 || s.size() == 0){
            return false;
        }
        
        if(n == 1){
            int address = atoi(s.c_str());
            if(address > 255 || (s.size() > 1 && s[0] == '0')){
                return false;
            }else{
                path.push_back(s);
                res.push_back(path);
                path.pop_back();
                return true;
            }
        }
        
        if(s[0] == '0'){
            path.push_back(s.substr(0,1));
            dfs(s.substr(1),n-1,path,res);
            path.pop_back();
        }else{
            for(int i = 0;i <= 3 && i < s.size(); ++i){
                int address = atoi(s.substr(0,i+1).c_str());
                if(address > 255){
                    continue;
                }
                path.push_back(s.substr(0,i+1));
                dfs(s.substr(i+1),n-1,path,res);
                path.pop_back();
            }
        }
        
        
        
        return true;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> path;
        vector<vector<string>> res;
        vector<string> ans;
        
        dfs(s,4,path,res);
        for(int i = 0;i < res.size(); ++i){
            string ip = res[i][0];
            for(int j = 1;j < res[i].size(); ++j){
                ip += "." + res[i][j];
            }
            ans.push_back(ip);
        }
        
        return ans;
    }
};
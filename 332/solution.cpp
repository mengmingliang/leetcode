class Solution {
public:    
    static bool cmp(string a, string b){
        return a < b;
    }
    
    bool dfs(int count,string start,vector<string> & path,map<pair<string,string>,int> & visited,map<string,vector<string>> & next){
        if(count == 0){
             return true;
        }
        
        for(auto e: next[start]){
             if(!visited[make_pair(start,e)]){
                 continue;
             }
             count--;
             path.push_back(e);
             visited[make_pair(start,e)] -= 1;
             if(dfs(count,e,path,visited,next)){
                 return true;
             }
             count++;
             path.pop_back();
             visited[make_pair(start,e)] += 1;
         }
        
         return false;
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        int n = tickets.size();
        map<string,vector<string>> next;
        map<pair<string,string>,int> visited;
        vector<string> ans;
        string start = "JFK";
        
        for(auto e : tickets){
            if(visited.find(make_pair(e.first,e.second)) !=  visited.end()){
                visited[make_pair(e.first,e.second)] += 1;
            }else{
                visited[make_pair(e.first,e.second)] = 1;
            }
            
            if(next.find(e.first) != next.end()){
                next[e.first].push_back(e.second);
            }else{
                vector<string> dst;
                dst.push_back(e.second);
                next[e.first].push_back(e.second);
            }
        }
        
        for(auto e:next){
            sort(next[e.first].begin(),next[e.first].end(),cmp);
        }
        
        ans.push_back(start);
        dfs(n,start,ans,visited,next);
        
        return ans;
    }
};
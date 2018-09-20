class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int,set<int>> graph;
        vector<int> degree(n,0);
        vector<int> ans;
        queue<int> qu;
        set<int> empty;
        
        if( n == 1){
            ans.push_back(0);
            return ans;
        }
        
        for(int i = 0;i < n; ++i){
            graph[i] = empty;
        }
        
        for(auto e: edges){
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
            degree[e.first]++;
            degree[e.second]++;
        }
        
        for(int i = 0;i < n; ++i){
            if(degree[i] == 1){
                qu.push(i);
            }
        }
        
        while(!qu.empty()){
            int level = qu.size();
            ans.clear();
            
            for(int i = 0;i < level; ++i){
                int cur = qu.front();
                ans.push_back(cur);
                qu.pop();
                degree[cur]--;
                
                for(auto next:graph[cur]){
                    if(degree[next] == 0){
                        continue;
                    }
                    if(degree[next] == 2){
                        qu.push(next);
                    }
                    degree[next]--;
                }
            }
        }
        
        return ans;
    }
};
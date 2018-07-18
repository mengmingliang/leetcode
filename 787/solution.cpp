class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        queue<pair<int,int>> qu;
        vector<vector<int>> price(n,vector<int>(n,0));
        vector<vector<int>> next(n,vector<int>());
        int ans = INT_MAX;
                
        for(auto l : flights){
            price[l[0]][l[1]] = l[2];
            next[l[0]].push_back(l[1]);
        }
        
        if(src == dst){
            return 0;
        }
        
        qu.push(make_pair(src,0));
        int step = 0;
        while(!qu.empty()){
            if(step > K){
                break;
            }
            
            int level = qu.size();
            for(int i = 0;i < level; ++i){
                pair<int,int> tmp = qu.front();
                qu.pop();
                int station = tmp.first;
                int cost = tmp.second;
                
                for(int j = 0;j < next[station].size(); ++j){
                    if(next[station][j] == dst){
                        ans = min(ans,cost + price[station][next[station][j]]);
                    }else{
                        qu.push(make_pair(next[station][j],cost + price[station][next[station][j]]));
                    }
                }
            }
            step++;
        }
        
        if(ans == INT_MAX){
            return -1;
        }
        
        return ans;
    }
};
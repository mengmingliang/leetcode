class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        queue<int,int> qu;
        vector<vector<int>> price(n,vector<int>(n,-1));
        vector<vector<int>> next(n,vector<int>());
        int ans = INT_MAX;
                
        for(int i = 0;i < flights.size(); ++i){
            price[flights[i][0]][flights[i][1]] = flights[i][2];
            next[flights[i][0]].push_back(flights[i][1]);
        }
        
        if(src == dst){
            return 0;
        }
        
        qu.push_back(make_pair(src,0));
        int step = 0;
        while(!qu.empty()){
            int level = qu.size();
            if(step > k){
                break;
            }
            
            for(int i = 0;i < level; ++i){
                pair<int,int> tmp = qu.front();
                qu.pop();
                int station = tmp.first;
                int cost = tmp.second;
                for(int j = 0;j < next[station].size(); ++j){
                    if(next[station][j] == dst){
                        ans = min(ans,cost + price[station][j]);
                    }else{
                        qu.push(make_pair(next[station][j],cost + price[station][j]));
                    }
                }
            }
            step++;
        }
        
        return ans;
    }
};
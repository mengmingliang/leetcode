#define RED 1
#define BLUE  -1
#define BLANK 0

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,BLANK);
        queue<int> qu;
        
        for(int i = 0; i < n; ++i){
            if(color[i] == BLANK){
                color[i] = RED;
                qu.push(i);
                while(!qu.empty()){
                    int next = qu.front();
                    qu.pop();
                    for(auto e: graph[next]){
                        if(color[e] == BLANK){
                            color[e] = -1*color[next];
                            qu.push(e);
                        }else{
                            if(color[e] == color[next]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
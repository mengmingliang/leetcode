#define RED 1
#define BLANK 0
#define BLUE -1

/*bfs*/
class Solution {
public:
   
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N,vector<int>());
        vector<int> color(N,BLANK);
        queue<int> qu;
        
        for(int i = 0;i < dislikes.size(); ++i){
            graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        
        for(int i = 0;i < N; ++i){
            if(color[i] == BLANK){
                qu.push(i);
                color[i] = RED;
                while(!qu.empty()){
                    int next = qu.front();
                    qu.pop();
                    for(auto e:graph[next]){
                        if(color[e] == BLANK){
                            color[e] = -1*color[next];
                            qu.push(e);
                        }else{
                            if(color[e] == color[next]){
                                return false;
                            }else{
                                continue;
                            }
                        }
                    }
                    
                }
            }
        }
        
        return true;
    }
};

/*DFS*/
class Solution {
public:
    bool dfs(vector<vector<int>> & graph,vector<int> & color,int idx,int c){
        if(idx < 0 || idx >= graph.size()){
            return false;
        }
        
        if(!((c == RED)||(c == BLUE)||(c == BLANK))){
            return false;
        }
        
        color[idx] = c;
        for(auto e: graph[idx]){
            if(color[e] == BLANK && dfs(graph,color,e,-1*c)){
                continue;
            }else{
                if(color[e] == c){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N,vector<int>());
        vector<int> color(N,BLANK);
        queue<int> qu;
        
        for(int i = 0;i < dislikes.size(); ++i){
            graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        
        for(int i = 0;i < N; ++i){
           if(color[i] == BLANK){
               if(!dfs(graph,color,i,RED)){
                   return false;
               }
           }
        }
        
        return true;
    }
};








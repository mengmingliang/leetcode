class Solution {
public:
    bool dfs(vector<vector<int>>& matrix,queue<pair<int,int>> & Q,vector<vector<bool>> &visited){
        int dir[4][2] = { {-1, 0}, { 0, 1 }, { 1, 0 }, {0, -1} };
        
        while(!Q.empty()){
            pair<int,int> cur = Q.front();
            Q.pop();
            
            for(int i = 0;i < 4; ++i){
                int x = dir[i][0] + cur.first;
                int y = dir[i][1] + cur.second;
                if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()){
                   continue;
                }
                if(matrix[cur.first][cur.second] > matrix[x][y] || visited[x][y]){
                    continue;
                }   
                   
                visited[x][y] = true;
                Q.push(make_pair(x,y));
            }
        }
        
        return true;
    }
    
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> ans;
        int r = matrix.size();
        if(r <= 0){
            return ans;
        }
        int c = matrix[0].size();
        if(c <= 0){
            return ans;
        }
        
        vector<vector<bool>> pacific(r,vector<bool>(c,false));
        vector<vector<bool>> atlantic(r,vector<bool>(c,false));
        queue<pair<int,int>> pQ;
        queue<pair<int,int>> aQ;
        
        for(int i = 0;i < r; ++i){
            pQ.push(make_pair(i,0));
            aQ.push(make_pair(i,c-1));
            pacific[i][0] = true;
            atlantic[i][c-1] = true;
        }
        
        for(int i = 0;i < c; ++i){
            pQ.push(make_pair(0,i));
            aQ.push(make_pair(r-1,i));
            pacific[0][i] = true;
            atlantic[r-1][i] = true;
        }
        
        dfs(matrix,pQ,pacific);
        dfs(matrix,aQ,atlantic);
        
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back(make_pair(i,j));
                }
            }
        }
        
        return ans;
    }
};
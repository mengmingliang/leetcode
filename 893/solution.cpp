class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        
        int row = grid.size();
        if(row <= 0){
            return 0;
        }
        int colum = grid[0].size();
        
        for(int i = 0;i < row; ++i){
            for(int j = 0;j < colum; ++j){
                if(grid[i][j] > 0){
                    ans++;/*top*/
                    ans++;/*buttom*/
                }
                /*left*/
                if(j == 0 || grid[i][j] > grid[i][j-1]){
                    if(j == 0){
                       ans += grid[i][j]; 
                    }else{
                       ans += grid[i][j]-grid[i][j-1];
                    }
                }
                0100000000000000000000000000000000000022654768000000002265476800
                /*right*/
                if(j == colum-1 || grid[i][j] > grid[i][j+1]){
                    if(j == colum-1){
                        ans += grid[i][j];
                    }else{
                        ans += grid[i][j] - grid[i][j+1];
                    }
                    
                }
                /*before*/
                if(i == 0 || grid[i][j] > grid[i-1][j]){
                    if(i == 0){
                        ans += grid[i][j];
                    }else{
                        ans += grid[i][j] - grid[i-1][j];
                    }
                    
                }
                /*back*/
                if(i == row-1 || grid[i][j] > grid[i+1][j]){
                    if( i == row-1){
                        ans += grid[i][j];
                    }else{
                        ans += grid[i][j] - grid[i+1][j];
                    }
                }
            }
        }
        
        return ans;
    }
};
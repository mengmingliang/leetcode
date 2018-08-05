class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int r = grid.size();
        int c = grid[0].size();
        int row_area = 0;
        int colum_area = 0;
        int down_area = 0;
        
        for(int i = 0;i < r; ++i){
            int max_row = 0;
            for(int j = 0;j < c; ++j){
                if(grid[i][j] > 0){
                    down_area++;
                }
                max_row = max(max_row,grid[i][j]);
            }
            row_area += max_row;
        }
        
        for(int i = 0;i < c; ++i){
            int max_colum = 0;
            for(int j = 0;j < r; ++j){
                max_colum = max(max_colum,grid[j][i]);
            }
            colum_area += max_colum;
        }
        
        ans = down_area + colum_area + row_area;
        
        return ans;
    }
};
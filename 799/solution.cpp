class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
       vector<vector<double>> capacity(101,vector<double>(101,0.0));
        
        capacity[0][0] = (double)poured;
        for(int i = 0; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                double remain = (capacity[i][j] - 1.0)/2;
                if(remain > 0){
                    capacity[i+1][j] += remain;
                    capacity[i+1][j+1] += remain;
                }
                
            }
        }
        return min(capacity[query_row][query_glass], 1.0);
    }
};
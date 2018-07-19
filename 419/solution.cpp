class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        int ans = 0;
        
        for(int i = 0 ;i < r; ++i){
            for(int j = 0;j < c; ++j){
                if(board[i][j] == 'X'){
                    ans++;
                    board[i][j] = '.';
                    /*row*/
                    for(int k = j+1;k < c && board[i][k] == 'X'; ++k){
                        board[i][k] = '.';
                    }
                    
                    /*colum*/
                    for(int k = i+1;k < r && board[k][j] == 'X'; ++k){
                        board[k][j] = '.';
                    }
                }
            }
        }
        
        return ans;
    }
};
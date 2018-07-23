class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x = 0;
        int o = 0;
        bool isLineX = false;
        bool isLineO = false;
        
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            if(board[0][0] == 'X'){
                isLineX = true;
            }
            if(board[0][0] == 'O'){
                isLineO = true;
            }
        }
        
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            if(board[1][1] == 'X'){
                isLineX = true;
            }
            if(board[1][1] == 'O'){
                isLineO = true;
            }
        }
        
        for(int i = 0;i < 3; ++i){
            for(int j = 0;j < 3; ++j){
                if(board[i][j] == 'X'){
                    x++;
                }
                if(board[i][j] == 'O'){
                    o++;
                }
            }
            if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
                if(board[i][0] == 'X'){
                    isLineX = true;
                }
                if(board[i][0] == 'O'){
                    isLineO = true;
                }
            }
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                if(board[0][i] == 'X'){
                    isLineX = true;
                }
                if(board[0][i] == 'O'){
                    isLineO = true;
                }
            }            
        }
        
        if(o > x||x-o >= 2){
            return false;
        }
        
        if(isLineX&&x==o){
            return false;
        }
        if(isLineO&&x-o==1){
            return false;
        }
        
        return true;
    }
};
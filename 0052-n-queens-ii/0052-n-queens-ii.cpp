class Solution {
public:
    int count = 0;
    bool issafe(vector<string>& board, int row, int col, int n){
        for(int i=0;i<row;i++){
            if(board[i][col]=='q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {

            if(board[i][j]=='q')
                return false;
            
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j]=='q')
                return false;
        }
        return true;
    }
    void solve(vector<string>& board,int row, int n){
        if(row == n){
            count++;
            return;
        }
        for(int col=0;col<n;col++){
            if(issafe(board,row,col,n)){
                board[row][col]='q';

                solve(board,row+1,n);

                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));

        solve(board,0,n);

        return count;
        
    }
};
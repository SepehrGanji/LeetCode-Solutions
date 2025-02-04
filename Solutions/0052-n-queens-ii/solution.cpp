class Solution {
public:
    bool canplacequeen(int row,int col,vector<string>&board){
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<board.size();i--,j++){
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    void solvequeen(int row,vector<string> &board,int &count){
        if(row==board.size()){
            count++;
            return;
        }
        for(int col=0;col<board.size();col++){
            if(canplacequeen(row,col,board)){
                board[row][col]='Q';
                solvequeen(row+1,board,count);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int count=0;
        vector<string> board(n,string(n,'.'));
        solvequeen(0,board,count);
        return count;
    }
};

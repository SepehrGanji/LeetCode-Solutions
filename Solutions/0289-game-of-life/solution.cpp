class Solution {
public:
    int cnt(vector<vector<int>>& board,int i,int j,int n ,int m){
        int count=0;
        int dirRow[8] ={-1, -1, -1, 0, +1, +1, +1, 0};
        int dirCol[8] ={-1, 0, +1, +1, +1, 0, -1, -1};
        for(int k=0;k<8;k++){
            int nx=i+dirRow[k];
            int ny=j+dirCol[k];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if((board[nx][ny]%2)==1) count++; // %2 for getting the original cell value .
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(); 
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live=cnt(board,i,j,n,m);
                if(board[i][j]==0 && live==3){
                    board[i][j]=2; // means alive
                }else if(board[i][j]==1){
                    if(live<2){
                        board[i][j]=3; // 3 means dead
                    }else if(live==2 || live==3){
                        board[i][j]=1;
                    }else if(live>3){
                        board[i][j]=3;
                    }
                }

            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==3){
                    board[i][j]=0;
                }else if(board[i][j]==2){
                    board[i][j]=1;
                }
            }
        }
    }
};

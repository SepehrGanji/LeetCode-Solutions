class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        priority_queue<tuple<int, int, int, bool>, vector<tuple<int, int, int, bool>>, greater<>> qu;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        qu.push({0,0,0, true});
        while(!qu.empty()){
            auto [t, row, col, check] = qu.top();
            qu.pop();
            if(row==n-1 && col==m-1) return t;
            int drow[4]={0,-1,0,1};
            int dcol[4]={-1,0,1,0};
            int tt = check ? 1 : 2;
            for(int i=0;i<4;i++){
                int n_row=row+drow[i];
                int n_col=col+dcol[i];
                
                if(n_row>=0 && n_row<n && n_col>=0 && n_col<m ){
                    int diff=max(t,moveTime[n_row][n_col])+tt;
                    
                    if(diff<dist[n_row][n_col]){
                        dist[n_row][n_col]=diff;
                        qu.push({diff,n_row,n_col, !check});
                    }
                    
                }
            }
        }
        
        return -1;
        
    }
};

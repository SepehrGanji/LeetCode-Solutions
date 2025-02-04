class Solution {
public:
    vector<string> ans;
    map<string, int> mp;
    vector<vector<int>> vis;
    void solve(int r, int c, string temp, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        if (mp.find(temp)!=mp.end()){
            mp.erase(temp);
            ans.push_back(temp);
        }
        if(temp.length()>=10) return;
        if(r<0 || c<0 || r>=n || c>=m) return;
        vis[r][c] = 1;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr<n && nc<m && nr>=0 && nc>=0 && !vis[nr][nc]){
                temp.push_back(board[nr][nc]);
                // cout<<temp<<" ";
                solve(nr, nc, temp, board);
                temp.pop_back();
            }
        }
        vis[r][c] = 0;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        vis.assign(n, vector<int>(m, 0));
        for(auto it: words){
            mp[it]++;
        }
        map<char, int> mp2;
        for(auto it: words){
            mp2[it[0]]++;
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(mp2.find(board[i][j])!=mp2.end()){
                    string s;
                    s.push_back(board[i][j]);
                    solve(i, j, s, board);
                }
            }
        }
        return ans;
    }
};

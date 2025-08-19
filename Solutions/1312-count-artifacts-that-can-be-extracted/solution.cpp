class Solution {
public:
    bool digi[1001][1001];

    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int ans = 0;
        for(auto el: dig) {
            int a = el[0], b = el[1];
            digi[a][b] = 1;
        }

        for(auto el: artifacts) {
            int i = el[0], j = el[1], ii = el[2], jj = el[3];
            bool all = true;
            if(i != ii && j != jj) {
                // four cell art
                if(!digi[i][j]) all = false;
                if(!digi[i+1][j+1]) all = false;
                if(!digi[i][j+1]) all = false;
                if(!digi[i+1][j]) all = false;
            } else if(i != ii) {
                // vertical art
                for(int mmd = i ; mmd <= ii ; mmd++) if(!digi[mmd][j]) all = false;
            } else {
                // horizontal art
                for(int mmd = j ; mmd <= jj ; mmd++) if(!digi[i][mmd]) all = false;
            }
            if(all) ans++;
        }
        return ans;
    }
};

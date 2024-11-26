class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> degree(n, 0);
        for(auto edge: edges) {
            int a = edge[0], b = edge[1];
            degree[b]++;
        }
        int champ = -1, champ_cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(degree[i] == 0) {
                if(champ_cnt > 0) return -1;
                champ_cnt = 1;
                champ = i;
            }
        }
        return champ;
    }
};

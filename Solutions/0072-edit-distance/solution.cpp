class Solution {
public:
    vector<vector<int>> memo;
    int solve(string w1, string w2, int i, int j) {
        if(i == 0) return j;
        if(j == 0) return i;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if(w1[i-1] == w2[j-1]) return memo[i][j] = solve(w1, w2, i-1, j-1);
        int A = solve(w1, w2, i-1, j);
        int B = solve(w1, w2, i, j-1);
        int C = solve(w1, w2, i-1, j-1);
        return memo[i][j] = min(A, min(B, C)) + 1;
    }

    int minDistance(string word1, string word2) {
        memo.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return solve(word1, word2, word1.size(), word2.size());    
    }
};

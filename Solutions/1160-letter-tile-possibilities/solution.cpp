class Solution {
public:
    set<string> ans;
    
    void backtrack(vector<int>& count, string& so_far, int n) {
        if (so_far.length() == n) {
            return;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                count[i]--;
                char c = 'A' + i;
                so_far.push_back(c);
                ans.insert(so_far);
                backtrack(count, so_far, n);
                so_far.pop_back();
                count[i]++;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        vector<int> count(26, 0);
        for (char c : tiles) {
            count[c - 'A']++;
        }
        string so_far = "";
        backtrack(count, so_far, tiles.length());
        return ans.size();
    }
};


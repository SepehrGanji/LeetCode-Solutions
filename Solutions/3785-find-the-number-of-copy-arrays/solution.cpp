class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int l = bounds[0][0], r = bounds[0][1];
        for(int i = 1 ; i < original.size() ; i++) {
            int newl = bounds[i][0] - original[i] + original[0];
            int newr = bounds[i][1] - original[i] + original[0];
            l = max(l, newl);
            r = min(r, newr);
        }
        int diff = (r-l)+1;
        return max(diff, 0);
    }
};

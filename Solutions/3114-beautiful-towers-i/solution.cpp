class Solution {
public:
    long long solve(vector<int> heights, int piv) {
        int pivel = heights[piv];
        long long ans = pivel;
        int lst = pivel;
        for(int i = piv - 1 ; i >= 0 ; i--) {
            if(heights[i] > lst) {
                heights[i] = lst;
            }
            ans += heights[i];
            lst = heights[i];
        }
        lst = pivel;
        for(int i = piv + 1 ; i < heights.size() ; i++) {
            if(heights[i] > lst) {
                heights[i] = lst;
            }
            ans += heights[i];
            lst = heights[i];
        }
        return ans;
    }

    long long maximumSumOfHeights(vector<int>& heights) {
        long long ans = 0;
        for(int i = 0 ; i < heights.size() ; i++) {
            ans = max(ans, solve(heights, i));
        }
        return ans;    
    }
};

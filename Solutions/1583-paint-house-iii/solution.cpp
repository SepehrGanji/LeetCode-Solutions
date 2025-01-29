class Solution {
public:
    int dp[100][100][30];
    const int MAXIM = 1000001;
    
    int dipi(vector<int>& houses, vector<vector<int>>& cost, int targetNei, int curr_house,
        int neiCount, int prevColor) {
            if(curr_house == houses.size()) return neiCount == targetNei ? 0 : MAXIM;
            if(neiCount > targetNei) return MAXIM;
            if(dp[curr_house][neiCount][prevColor] != -1) return dp[curr_house][neiCount][prevColor];
            int ans = MAXIM;
            if(houses[curr_house] > 0) {
                // already painted
                int newNeiCount = neiCount;
                if(houses[curr_house] != prevColor) newNeiCount++;
                ans = dipi(houses, cost, targetNei, curr_house+1, newNeiCount, houses[curr_house]);
            } else {
                // to be painted
                for(int col = 1 ; col <= cost[0].size() ; col++) {
                    int newNeiCount = neiCount;
                    if(col != prevColor) newNeiCount++;
                    int newCost = cost[curr_house][col-1] + dipi(houses, cost, targetNei, curr_house+1, newNeiCount, col);
                    ans = min(ans, newCost);
                }
            }

            return dp[curr_house][neiCount][prevColor] = ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = dipi(houses, cost, target, 0, 0, 0);
        return ans == MAXIM ? -1 : ans;
    }
};

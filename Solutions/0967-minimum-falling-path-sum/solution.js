/**
 * @param {number[][]} matrix
 * @return {number}
 */
var minFallingPathSum = function(matrix) {
    let n = matrix.length;
    let dp = Array(n).fill(null).map(() => Array(n).fill(0));
    for(let j = 0 ; j < n ; j++) dp[0][j] = matrix[0][j];
    for(let i = 1 ; i < n ; i++) {
        for(let j = 0 ; j < n ; j++) {
            let mini = dp[i-1][j];
            if(j > 0) mini = Math.min(mini, dp[i-1][j-1]);
            if(j < n-1) mini = Math.min(mini, dp[i-1][j+1]);
            dp[i][j] = matrix[i][j] + mini;
        }
    }
    let ans = dp[n-1][0];
    for(let j = 1 ; j < n ; j++) ans = Math.min(ans, dp[n-1][j]);
    return ans;
};


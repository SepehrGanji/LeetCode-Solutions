/**
 * @param {string} s
 * @return {number}
 */
var numDecodings = function(s) {
    let n = s.length;
    s = " " + s;
    const dp = [];
    for(let i = 0 ; i <= n ; i++) dp.push(0);
    if(s[1] == '0') return 0;
    dp[0] = 1;
    for(let i = 1 ; i <= n ; i++) {
        if(s[i] == '0') {
            // must be with prev
            if(s[i-1] == '1' || s[i-1] == '2') dp[i] = dp[i-2];
            else return 0;
        } else {
            dp[i] = dp[i-1];
            // see if I can add i-2!
            if(s[i-1] == '1') {
                dp[i] += dp[i-2];
            } else if(s[i-1] == '2' && s[i] < '7') {
                dp[i] += dp[i-2];
            }
        }
    }
    return dp[n];
};


/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function(colors, neededTime) {
    let col = colors[0];
    let cnt = 1;
    let sum = neededTime[0];
    let maxi = neededTime[0];
    let ans = 0;
    for(let i = 1 ; i < neededTime.length ; i++) {
        if(colors[i] == col) {
            cnt++;
            sum += neededTime[i];
            maxi = Math.max(maxi, neededTime[i]);
        } else {
            if(cnt > 1) {
                ans += sum;
                ans -= maxi;
            }
            col = colors[i];
            cnt = 1;
            sum = neededTime[i];
            maxi = neededTime[i];
        }
    }
    if(cnt > 1) {
        ans += sum;
        ans -= maxi;
    }
    return ans;
};


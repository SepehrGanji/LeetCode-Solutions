/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let ans = 0;
    let curr = 0;
    for(let el of nums) {
        if(el == 0) {
            ans = Math.max(ans, curr);
            curr = 0;
        } else curr++;
    }
    ans = Math.max(ans, curr);
    return ans;    
};


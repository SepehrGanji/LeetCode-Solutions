/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    let n = nums.length;
    let ans = Array(n).fill(0);
    for(let i = 0 ; i < n ; i++) {
        let cnt = 0;
        for(let j = 0 ; j < n ; j++) {
            if(j != i && nums[j] < nums[i]) cnt++;
        }
        ans[i] = cnt;
    }
    return ans;
};


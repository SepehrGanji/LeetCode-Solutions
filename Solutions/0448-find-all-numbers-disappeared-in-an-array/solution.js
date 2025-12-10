/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    let n = nums.length;
    let appear = Array(n+1).fill(false);
    for(let el of nums) appear[el] = true;
    let ans = [];
    for(let i = 1 ; i <= n ; i++) if(!appear[i]) ans.push(i);
    return ans;
};


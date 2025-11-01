/**
 * @param {number[]} arr
 * @return {number}
 */
var countElements = function(arr) {
    let ans = 0;
    var mp = new Map();
    for(let el of arr) {
       mp[el] = 1; 
    }
    for(let el of arr) {
        ans += mp[el+1] || 0;
    }
    return ans;
};

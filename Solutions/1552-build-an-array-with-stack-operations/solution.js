/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function(target, n) {
    const ans = [];
    let current = 1;
    for(const el of target) {
        while(current !== el) {
            ans.push("Push");
            ans.push("Pop");
            current++;
        }
        ans.push("Push");
        current++;
    }
    return ans;
};


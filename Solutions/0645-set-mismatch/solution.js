/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function (nums) {
    const n = nums.length;
    const freq = Array(n + 1).fill(0);

    for (const x of nums) freq[x]++;

    let twice = 0, missing = 0;
    for (let i = 1; i <= n; i++) {
        if (freq[i] === 2) twice = i;
        if (freq[i] === 0) missing = i;
    }

    return [twice, missing];
};


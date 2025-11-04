/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findXSum = function(nums, k, x) {
    const xsum = (arr, x) => {
        let freqs = {};
        for (let n of arr) freqs[n] = (freqs[n] || 0) + 1;

        const nums = Object.keys(freqs).sort((a, b) => freqs[b] - freqs[a] || +b - +a);
        let sum = 0;
        for (let i = 0; i < Math.min(x, nums.length); i++)
            sum += nums[i] * freqs[nums[i]];

        return sum;
    };

    const n = nums.length;
    let res = new Array(n - k + 1).fill(0);
    for (let i = 0; i < res.length; i++)
        res[i] = xsum(nums.slice(i, i + k), x);

    return res;
};

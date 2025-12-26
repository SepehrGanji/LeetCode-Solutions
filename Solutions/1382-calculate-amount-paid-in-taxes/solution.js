/**
 * @param {number[][]} brackets
 * @param {number} income
 * @return {number}
 */
var calculateTax = function(brackets, income) {
    let ans = 0;
    let rem = income;
    let lst = 0;
    let i = 0;
    while(rem > 0) {
        const current = brackets[i++];
        const upper = current[0], rate = current[1];
        const money = upper - lst; lst = upper;
        if(rem < money) {
            // partial coverage, all of rem is taxed
            ans += (rem * rate) / 100;
            rem = 0;
        } else {
            // full coverage, the money is taxed
            ans += (money * rate) / 100;
            rem -= money;
        }
    }
    return ans;
};


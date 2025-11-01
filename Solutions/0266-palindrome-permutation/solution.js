/**
 * @param {string} s
 * @return {boolean}
 */
var canPermutePalindrome = function(s) {
    let oddcnt = 0;
    let mp = new Map();
    for(let ch of s) {
        mp.set(ch, (mp.get(ch) || 0) + 1);
    }

    for(const [key, value] of mp) {
        if(value % 2 == 1) oddcnt++;
    }

    if(oddcnt > 1) return false;
    return true;
};

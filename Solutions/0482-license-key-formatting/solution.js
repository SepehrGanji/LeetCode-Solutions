/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var licenseKeyFormatting = function(s, k) {
    const arr = s.split("-").reverse().map(el => el.split("").reverse().join("")).join("").toUpperCase();
    const n = arr.length;
    let ans = "";
    for(let i = 0 ; i < n ; i += k) {
        for(let j = i ; j < i + k && j < n ; j++) {
            ans += arr[j];
        }
        ans += '-';
    }
    const m = ans.length;
    ans = ans.substr(0, m-1);
    return ans.split("").reverse().join("")
};


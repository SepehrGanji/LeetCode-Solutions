/**
 * Encodes a list of strings to a single string.
 *
 * @param {string[]} strs
 * @return {string}
 */
var encode = function(strs) {
    let ans = "";
    const delim = String.fromCharCode(300);
    for(let i = 0 ; i < strs.length ; i++) {
        ans += strs[i];
        if(i < strs.length - 1) ans += delim;
    }
    return ans;
};

/**
 * Decodes a single string to a list of strings.
 *
 * @param {string} s
 * @return {string[]}
 */
var decode = function(s) {
    const delim = String.fromCharCode(300);
    return s.split(delim);
};

/**
 * Your functions will be called as such:
 * decode(encode(strs));
 */

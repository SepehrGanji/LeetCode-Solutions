/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

const validate = (a, b) => {
    let i = 0;
    const n = a.length;
    while(i < n && a[i] === b[i]) i++;
    while(i < n) {
        if(a[i] !== b[i+1]) return false;
        i++;
    }
    return true;
};

var isOneEditDistance = function(s, t) {
    if(s === t) return false;
    const n = s.length;
    const m = t.length;
    if(Math.abs(n-m) >= 2) return false;
    if(n === m) {
        let diff = 0;
        for(let i = 0 ; i < n ; i++) {
            if(s[i] !== t[i]) diff++;
        }
        return diff === 1;
    }else if(n < m) {
        return validate(s, t);
    } else {
        return validate(t, s);
    }
};


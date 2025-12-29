/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} coordinates
 * @return {number[]}
 */

const isValid = (i, j, n, m) => {
    if( i < 0 || i >= n) return false;
    if( j < 0 || j >= m) return false;
    return true;
};

const mp = new Map(); // [x, y] -> cnt

const add = (i, j, m) => {
    const val = (i * m) + j;
    let curr = mp.has(val) ? mp.get(val) : 0;
    curr++;
    mp.set(val, curr);
} 

var countBlackBlocks = function(n, m, coordinates) {
    mp.clear();
    for(const [i, j] of coordinates) {
        if(i === n-1 && j === m-1) {
            add(i-1, j-1, m);
        } else if(i === n-1) {
            // last row
            if(isValid(i-1, j, n, m)) add(i-1, j, m);
            if(isValid(i-1, j-1, n, m)) add(i-1, j-1, m);
        } else if(j === m-1) {
            // last column
            if(isValid(i, j-1, n, m)) add(i, j-1, m);
            if(isValid(i-1, j-1, n, m)) add(i-1, j-1, m);
        } else {
            add(i, j, m);
            if(isValid(i-1, j, n, m)) add(i-1, j, m);
            if(isValid(i, j-1, n, m)) add(i, j-1, m);
            if(isValid(i-1, j-1, n, m)) add(i-1, j-1, m);
        }
    }
    const ans = [0, 0, 0, 0, 0];
    for(const [key, value] of mp) {
        ans[value]++;
    }
    const sum = ans.reduce((acc, cur) => acc + cur, 0);
    ans[0] = ((n-1)*(m-1)) - sum;
    return ans;
};


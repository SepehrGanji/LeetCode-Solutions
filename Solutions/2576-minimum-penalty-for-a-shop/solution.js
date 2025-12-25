/**
 * @param {string} customers
 * @return {number}
 */
var bestClosingTime = function(customers) {
    const n = customers.length;
    const pfx = Array(n).fill(0);
    const sfx= Array(n).fill(0);
    if(customers[0] === 'N') pfx[0] = 1;
    for(let i = 1 ; i < n ; i++) {
        pfx[i] = pfx[i-1];
        if(customers[i] === 'N') pfx[i]++;
    }
    if(customers[n-1] === 'Y') sfx[n-1] = 1;
    for(let i = n - 2 ; i >= 0 ; i--) {
        sfx[i] = sfx[i+1];
        if(customers[i] === 'Y') sfx[i]++;
    }
    let ans = -1, min_value = 10000000;
    for(let i = 0 ; i <= n ; i++) {
        let cost = 0;
        if(i > 0) cost += pfx[i-1];
        if(i < n) cost += sfx[i];
        if(cost < min_value) {
            min_value = cost;
            ans = i;
        }
    }
    return ans;
};

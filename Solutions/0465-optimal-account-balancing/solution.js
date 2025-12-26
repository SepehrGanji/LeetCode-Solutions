/**
 * @param {number[][]} transactions
 * @return {number}
 */

function dfs(i, arr) {
    while(i < arr.length && arr[i] === 0) i++;
    if(i === arr.length) return 0;
    let mini = 1000000;
    for(let nex = i + 1 ; nex < arr.length ; nex++) {
        arr[nex] += arr[i];
        mini = Math.min(mini, dfs(i+1, arr) + 1);
        arr[nex] -= arr[i];
    }
    return mini;
};

var minTransfers = function(transactions) {
    const people = Array(15).fill(0);
    for(const tx of transactions) {
        const from = tx[0], to = tx[1], amount = tx[2];
        people[from] -= amount;
        people[to] += amount;
    }
    const arr = [];
    for(let i = 0 ; i < 15 ; i++) if(people[i] != 0) arr.push(people[i]);
    return dfs(0, arr);
};


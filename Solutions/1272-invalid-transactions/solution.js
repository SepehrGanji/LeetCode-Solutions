/**
 * @param {string[]} transactions
 * @return {string[]}
 */
var invalidTransactions = function(transactions) {
    const txs = transactions.map(el => {
        const parsed = el.split(',');
        return {
            name: parsed[0],
            time: Number(parsed[1]),
            amount: Number(parsed[2]),
            city: parsed[3],
            full: el,
            valid: true
        };
    });
    const mp = new Map(); // name -> [tx]
    for(const tx of txs) {
        if(tx.amount > 1000) tx.valid = false;
        const prev_txs = mp.has(tx.name) ? mp.get(tx.name) : [];
        for(const ptx of prev_txs) {
            if(Math.abs(tx.time - ptx.time) <= 60 && tx.city !== ptx.city) {
                ptx.valid = false;
                tx.valid = false;
            }
        }
        prev_txs.push(tx);
        mp.set(tx.name, prev_txs);
    }
    const invalids = [];
    for(const [key, val] of mp) {
        for(const tx of val) {
            if(!tx.valid) invalids.push(tx.full);
        }
    }
    return invalids;
};

/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function(equations, values, queries) {
    const gr = new Map(); // a -> [[b, 2], ...]
    const n = equations.length;
    for(let i = 0 ; i < n ; i++) {
        const a = equations[i][0];
        const b = equations[i][1];
        const val = values[i];
        const mpa = gr.has(a) ? gr.get(a) : [];
        mpa.push([b, val]);
        gr.set(a, mpa);
        const mpb = gr.has(b) ? gr.get(b) : [];
        mpb.push([a, 1.0 / val]);
        gr.set(b, mpb);
    }
    const ans = [];
    for(const q of queries) {
        const a = q[0], b = q[1];
        if(gr.has(a) && gr.has(b)) {
            const qq = [[a, 1]];
            const visited = new Set();
            let success = false;
            visited.add(a);
            while(qq.length > 0) {
                const [node, val] = qq.shift();
                if(node == b) {
                    ans.push(val);
                    success = true;
                    break;
                }
                for(const [nei, wei] of gr.get(node)) {
                    if(!visited.has(nei)) {
                        visited.add(nei);
                        qq.push([nei, val * wei]);
                    }
                }
            }
            if(!success) ans.push(-1.00);
        } else {
            ans.push(-1.00);
        }
    }
    return ans;
};


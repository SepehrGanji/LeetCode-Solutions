/**
 * @param {number} n
 * @param {number[][]} flights
 * @param {number} src
 * @param {number} dst
 * @param {number} k
 * @return {number}
 */
var findCheapestPrice = function(n, flights, src, dst, k) {
    k++;
    const graph = Array.from({ length: n }, () => []);
    for(const flight of flights) {
        const [a, b, cost] = flight;
        graph[a].push([b, cost]);
    }
    let ans = Number.MAX_SAFE_INTEGER;
    const visited = Array(n).fill(Number.MAX_SAFE_INTEGER);
    visited[src] = 0;
    const q = [[src, 0, 0]]; // city, cost_so_far, hop_so_far
    while(q.length > 0) {
        const [node, cost, hops] = q.shift();
        if(hops > k) continue;
        if(node === dst) {
            ans = Math.min(ans, cost);
            continue;
        }
        if(hops === k) continue;
        for(const nei of graph[node]) {
            const [node2, cost2] = nei;
            if(cost + cost2 < visited[node2]) {
                visited[node2] = cost + cost2;
                q.push([node2, visited[node2], hops+1]);
            }
        }
    }
    if(ans == Number.MAX_SAFE_INTEGER) return -1;
    return ans;
};


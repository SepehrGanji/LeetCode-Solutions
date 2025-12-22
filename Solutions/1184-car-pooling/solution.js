/**
 * @param {number[][]} trips
 * @param {number} capacity
 * @return {boolean}
 */
var carPooling = function(trips, capacity) {
    const prefix_array = Array(1010).fill(0);
    for(const trip of trips) {
        const num = trip[0], from = trip[1], to = trip[2];
        prefix_array[from] += num;
        prefix_array[to] -= num;
    }
    let current_pass = 0;
    for(let i = 0 ; i <= 1000 ; i++) {
        
        if(current_pass > capacity) return false;
        current_pass += prefix_array[i];
    }
    return true;
};

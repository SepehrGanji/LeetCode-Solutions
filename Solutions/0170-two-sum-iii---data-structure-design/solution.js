
var TwoSum = function() {
    this.arr = [];
    this.sorted = false;
};

/** 
 * @param {number} number
 * @return {void}
 */
TwoSum.prototype.add = function(number) {
    this.arr.push(number);
    this.sorted = false;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
TwoSum.prototype.find = function(value) {
    if(!this.sorted) {
        this.arr.sort((a, b) => a-b);
        this.sorted = true;
    }

    let l = 0, r = this.arr.length - 1;
    while(l < r) {
        const sum = this.arr[l] + this.arr[r];
        if(sum < value) l++;
        else if(sum > value) r--;
        else return true;
    }
    return false;
};

/** 
 * Your TwoSum object will be instantiated and called as such:
 * var obj = new TwoSum()
 * obj.add(number)
 * var param_2 = obj.find(value)
 */

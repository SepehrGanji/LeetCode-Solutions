/**
 * @param {number[][]} vec
 */
var Vector2D = function(vec) {
    this.arr = [];
    for(let el of vec) {
        for(let elel of el) {
            this.arr.push(elel);
        }
    }
    this.i = 0;
};

/**
 * @return {number}
 */
Vector2D.prototype.next = function() {
    return this.arr[this.i++];
};

/**
 * @return {boolean}
 */
Vector2D.prototype.hasNext = function() {
    return this.i < this.arr.length;
};

/** 
 * Your Vector2D object will be instantiated and called as such:
 * var obj = new Vector2D(vec)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */

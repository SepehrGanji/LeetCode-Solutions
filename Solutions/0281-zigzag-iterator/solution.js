/**
 * @constructor
 * @param {Integer[]} v1
 * @param {Integer[]} v1
 */
var ZigzagIterator = function ZigzagIterator(v1, v2) {
    this.arr = v1;
    this.arr2 = v2;
    this.i = 0;
    this.j = 0;
    this.zig = false;
};


/**
 * @this ZigzagIterator
 * @returns {boolean}
 */
ZigzagIterator.prototype.hasNext = function hasNext() {
    if(this.i >= this.arr.length && this.j >= this.arr2.length) return false;
    return true;
};

/**
 * @this ZigzagIterator
 * @returns {integer}
 */
ZigzagIterator.prototype.next = function next() {
    if(this.i >= this.arr.length) return this.arr2[this.j++];
    if(this.j >= this.arr2.length) return this.arr[this.i++];
    if(this.zig) {
        this.zig = false;
        return this.arr2[this.j++];
    }
    this.zig = true;
    return this.arr[this.i++];
};

/**
 * Your ZigzagIterator will be called like this:
 * var i = new ZigzagIterator(v1, v2), a = [];
 * while (i.hasNext()) a.push(i.next());
*/

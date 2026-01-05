/**
 * // This is the Iterator's API interface.
 * // You should not implement it, or speculate about its implementation.
 * function Iterator() {
 *    @ return {number}
 *    this.next = function() { // return the next number of the iterator
 *       ...
 *    }; 
 *
 *    @return {boolean}
 *    this.hasNext = function() { // return true if it still has numbers
 *       ...
 *    };
 * };
 */

/**
 * @param {Iterator} iterator
 */
var PeekingIterator = function(iterator) {
    this.it = iterator;
    this.nex = -1;
};

/**
 * @return {number}
 */
PeekingIterator.prototype.peek = function() {
    if(this.nex === -1) this.nex = this.it.next();
    return this.nex;
};

/**
 * @return {number}
 */
PeekingIterator.prototype.next = function() {
    if(this.nex === -1) return this.it.next();
    const val = this.nex;
    this.nex = -1;
    return val;
};

/**
 * @return {boolean}
 */
PeekingIterator.prototype.hasNext = function() {
    if(this.nex !== -1) return true;
    return this.it.hasNext();
};

/** 
 * Your PeekingIterator object will be instantiated and called as such:
 * var obj = new PeekingIterator(arr)
 * var param_1 = obj.peek()
 * var param_2 = obj.next()
 * var param_3 = obj.hasNext()
 */

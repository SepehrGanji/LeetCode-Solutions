
var MyStack = function() {
    this.qu = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.qu.push(x);
    let sz = this.qu.length;
    while(sz > 1) {
        sz--;
        this.qu.push(this.qu.shift());
    }
};

/**
 * @return {number}
 */
MyStack.prototype.pop = function() {
    return this.qu.shift();
};

/**
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.qu.at(0);
};

/**
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.qu.length === 0;
};

/** 
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */

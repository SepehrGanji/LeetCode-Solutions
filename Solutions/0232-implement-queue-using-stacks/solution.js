var MyQueue = function() {
    this.input = [];
    this.output = [];
};

MyQueue.prototype.push = function(x) {
    this.input.push(x);    
};

MyQueue.prototype.pop = function() {
    this.peek();
    return this.output.pop();    
};

MyQueue.prototype.peek = function() {
    if (!this.output.length) {
        while (this.input.length) {
            this.output.push(this.input.pop());
        }
    }

    return this.output[this.output.length - 1];    
};

MyQueue.prototype.empty = function() {
    return !this.input.length && !this.output.length;    
};

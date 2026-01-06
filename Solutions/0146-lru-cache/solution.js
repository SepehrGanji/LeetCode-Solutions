/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.head = null;
    this.tail = null;
    this.mp = new Map();
    this.cap = capacity;
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if(this.mp.has(key) === false) return -1;
    const curr = this.mp.get(key);
    if(curr === this.tail) return curr.val;
    if(curr.prev !== null) curr.prev.next = curr.next;
    if(curr.next !== null) curr.next.prev = curr.prev;
    if(curr === this.head) this.head = this.head.next;
    this.tail.next = curr;
    curr.prev = this.tail;
    this.tail = curr;
    return curr.val;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if(this.get(key) !== -1) {
        this.mp.get(key).val = value;
        return;
    }
    const curr = {
        val: value,
        key: key,
        next: null,
        prev: null
    };
    this.mp.set(key, curr);
    if(this.head === null) {
        this.head = curr;
        this.tail = curr;
        return;
    }
    this.tail.next = curr;
    curr.prev = this.tail;
    this.tail = curr;
    if(this.mp.size > this.cap) {
        this.mp.delete(this.head.key);
        this.head = this.head.next;
        this.head.prev = null;
    }
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */

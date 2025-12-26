/**
 * @param {number[]} balance
 */

let arr = [];
let n;

var Bank = function(balance) {
    arr = [];
    for(const el of balance) arr.push(el);
    n = arr.length;
};

/** 
 * @param {number} account1 
 * @param {number} account2 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.transfer = function(account1, account2, money) {
    if(account1 < 1 || account1 > n) return false;
    if(account2 < 1 || account2 > n) return false;
    if(arr[account1-1] < money) return false;
    arr[account1-1] -= money;
    arr[account2-1] += money;
    return true;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.deposit = function(account, money) {
    if(account < 1 || account > n) return false;
    arr[account-1] += money;
    return true;
};

/** 
 * @param {number} account 
 * @param {number} money
 * @return {boolean}
 */
Bank.prototype.withdraw = function(account, money) {
    if(account < 1 || account > n) return false;
    if(arr[account-1] < money) return false;
    arr[account-1] -= money;
    return true;
};

/** 
 * Your Bank object will be instantiated and called as such:
 * var obj = new Bank(balance)
 * var param_1 = obj.transfer(account1,account2,money)
 * var param_2 = obj.deposit(account,money)
 * var param_3 = obj.withdraw(account,money)
 */

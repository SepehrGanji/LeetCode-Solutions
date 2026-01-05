/**
 * @param {string[]} wordsDict
 */
var WordDistance = function(wordsDict) {
    this.arr = wordsDict;
};

/** 
 * @param {string} word1 
 * @param {string} word2
 * @return {number}
 */
WordDistance.prototype.shortest = function(word1, word2) {
    let ans = 1000000;
    let oc1 = -1, oc2 = -1;
    for(let i = 0 ; i < this.arr.length ; i++) {
        if(this.arr[i] === word1) oc1 = i;
        if(this.arr[i] === word2) oc2 = i;
        if(oc1 >= 0 && oc2 >= 0) ans = Math.min(Math.abs(oc1-oc2), ans);
    }
    return ans;
};

/** 
 * Your WordDistance object will be instantiated and called as such:
 * var obj = new WordDistance(wordsDict)
 * var param_1 = obj.shortest(word1,word2)
 */

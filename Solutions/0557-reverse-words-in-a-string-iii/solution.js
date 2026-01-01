/**
 * @param {string} s
 * @return {string}
 */
function reverse(s){
    return s.split("").reverse().join("");
}

var reverseWords = function(s) {
    return s.split(' ').map(el => reverse(el)).join(' ');
};


/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    const stack = [];
    for(const tok of tokens) {
        const nn = tok.length - 1;
        if(tok.charCodeAt(nn) >= '0'.charCodeAt(0) && tok.charCodeAt(nn) <= '9'.charCodeAt(0)) {
            stack.push(Number(tok));
        } else {
            const el2 = stack.pop();
            const el1 = stack.pop();
            let ans = 0;
            if(tok == '+') {
                ans = el1 + el2;
            } else if(tok == '-') {
                ans = el1 - el2;
            } else if(tok == '/') {
                ans = Math.floor(el1 / el2);
                if(ans < 0 && el1 % el2 != 0) ans++;
            } else {
                ans = el1 * el2;
            }
            stack.push(ans);
        }
    }
    const ans = stack.pop();
    return ans;
};


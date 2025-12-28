/**
 * @param {string} s
 * @return {string[]}
 */

const solve = (arr, i) => {
    if(i >= arr.length) return [""];
    const ans = [];
    const nex = solve(arr, i+1);
    for(const el of arr[i]) {
        for(const el2 of nex) {
            ans.push(el + el2);
        }
    }
    return ans;
}

var expand = function(s) {
    const arr = [];
    let i = 0, n = s.length;
    while(i < n) {
        if(s[i] == '{') {
            // navigate the whole {}
            const local_arr = [];
            i++;
            while(s[i] != '}') {
                if(s[i] != ',') local_arr.push(s[i]);
                i++;
            }
            arr.push(local_arr);
        } else {
            // just a single letter
            arr.push([s[i]]);
        }
        i++;
    }
    const ans = solve(arr, 0).sort();
    return ans;
};

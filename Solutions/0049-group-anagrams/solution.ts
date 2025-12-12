function groupAnagrams(strs: string[]): string[][] {
    const mp: Map<string, string[]> = new Map();
    for(const el of strs) {
        const sorted = el.split('').sort().join('');
        const arr = mp.get(sorted);
        if(arr) arr.push(el);
        else mp.set(sorted, [el]);
    }
    const ans: string[][] = [];
    for(const [key, val] of mp) {
        ans.push(val);
    }
    return ans;
};


function topKFrequent(nums: number[], k: number): number[] {
    const mp: Map<number, number> = new Map();
    for(const el of nums) {
        const fr = mp.get(el);
        if(fr) mp.set(el, fr + 1);
        else mp.set(el, 1);
    }
    const arr: [number, number][] = [];
    for(const [num, freq] of mp) {
        arr.push([freq, num]);
    }
    arr.sort((a, b) => b[0] - a[0]);
    const ans: number[] = [];
    for(let i = 0 ; i < k ; i++) {
        ans.push(arr[i][1]);
    }
    return ans;
};

